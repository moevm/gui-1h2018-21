#include "gamescreenview.h"
#include <iostream>

GameScreenView::GameScreenView(QWidget *parent)
{

        car = new CarItem();
        coinTimer = new QTimer();
        sceneTimer = new QTimer();
        accelerationTimer = new QTimer();
        scene = new QGraphicsScene();

        upCarMovementIsBlocked = false;
        downCarMovementIsBlocked = false;
        sceneMovementSpeed = 5;
        sceneAcceleration = 1;
        coinsNumber = 20;
        sceneTimerRate = 30;
        accelerationTimerRate = 1500;
        sceneLenght = 12000;
        coinVecIndex = 0;
        currentScore = 0;

        coins.push_back(new CoinItem());
        coins.push_back(new CoinItem());
        putCoins();


        sceneBackground.load(":/resource/img/GamePic.jpg");
        scene->addItem(car);
        for(int i=0; i<coinsNumber; i++)
            scene->addItem(coins[i]);
        scene->setSceneRect(0, 0, sceneLenght, getDesktopHeight()-2);
        scene->setBackgroundBrush(sceneBackground.scaledToHeight(scene->height()));


        this->setScene(scene);
        this->setTransformationAnchor(NoAnchor);
        this->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
        this->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
        this->setCursor(Qt::BlankCursor);


        if(!coins.empty())
            coinTimer->setInterval(coins[0]->getCoinSpinningSpeed());
        sceneTimer->setInterval(sceneTimerRate);
        accelerationTimer->setInterval(accelerationTimerRate);


        connect(coinTimer, SIGNAL(timeout()), this, SLOT(updateCoinImage()));
        connect(sceneTimer, SIGNAL(timeout()), this, SLOT(updateSceneState()));
        connect(accelerationTimer, SIGNAL(timeout()), this, SLOT(updateAcceleration()));



        coinTimer->start();
        sceneTimer->start();
        accelerationTimer->start();

}



void GameScreenView::keyPressEvent(QKeyEvent *keyEvent){

    switch (keyEvent->key()) {
        case Qt::Key_Down:
            if(!downCarMovementIsBlocked)
                car->moveBy(0, car->getMovementSpeed());
            break;
        case Qt::Key_Up:
            if(!upCarMovementIsBlocked)
                car->moveBy(0, -car->getMovementSpeed());
            break;
        default:
            break;
    }
}

int GameScreenView::getDesktopHeight(){
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    return height;
}

int GameScreenView::getDesktopWidth(){
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int width = screenGeometry.width();
    return width;
}


void GameScreenView::setSceneLength(int len)
{
    sceneLenght = len;
}

void GameScreenView::putCoins()
{
    srand (time(0));

    int coinLocationInterval = sceneLenght / (coinsNumber + 1);
    int intervalNumber = 1;

    for(int i=0; i<coinsNumber;i++){
        coins.push_back(new CoinItem());
        int x = rand() % coinLocationInterval + coinLocationInterval*intervalNumber;
        double y = rand() % getDesktopHeight()/2.8  + getDesktopHeight()/1.8 ;
        coins[i]->setPos(x, y);
        intervalNumber++;
    }


    std::cout << getDesktopHeight()/2.24 << " " << getDesktopHeight()/1.8 << " " << getDesktopHeight() << std::endl;

}


void GameScreenView::wheelEvent(QWheelEvent *event)
{

}

int GameScreenView::getSceneLength()
{
    return sceneLenght;
}

GameScreenView::~GameScreenView(){

}

void GameScreenView::updateCoinImage()
{

    if(coins.empty())
        return;

    if(coinVecIndex == coins[0]->getCoinImageSources().size())
        coinVecIndex = 0;


    for(int i=0; i< coinsNumber; i++){
        coins[i]->setPixmap(QPixmap::fromImage(QImage(coins[i]->getCoinImageSources().at(coinVecIndex).data())));
    }

    coinVecIndex++;
}


void GameScreenView::updateAcceleration(){
    sceneMovementSpeed += sceneAcceleration;
}

void GameScreenView::updateSceneState()
{


    translate(-sceneMovementSpeed, 0);
    car->moveBy(sceneMovementSpeed, 0);


    std::vector<CoinItem*>::iterator it;
    for ( it = coins.begin(); it != coins.end(); it++){
        if((*it)->collidesWithItem(car)){
            currentScore += coinPoints;
            scene->removeItem(*it);
            coinsNumber--;
            if(coins.size() == 1){
                coins.clear();
                break;
            }
            coins.erase(it);
            it = coins.begin();
        }
    }

    if(car->pos().y() > getDesktopHeight() - (car->pixmap().height()/4 + 10))
        downCarMovementIsBlocked = true;
    else
        downCarMovementIsBlocked = false;

    if(car->pos().y() < getDesktopHeight()/1.8)
        upCarMovementIsBlocked = true;
    else
        upCarMovementIsBlocked = false;


    if(car->pos().x() > sceneLenght){

        sceneTimer->stop();
        accelerationTimer->stop();

        winLabel = new WinLabelItem(getDesktopHeight(), getDesktopWidth());
        scene->addItem(winLabel);

        int winLocX = mapToScene(pos()).x()+getDesktopWidth()/2 - winLabel->pixmap().width() * (winLabel->scale() / 2);
        int winLocY = -winLabel->pixmap().height() * 2 ;

        winLabel->setPos(winLocX, winLocY);
        winLabel->animatedMoveToScenePos(winLocX, getDesktopHeight()/2 - winLabel->pixmap().height() * 2);


    }
}

