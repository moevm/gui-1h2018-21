#include "gamescreenview.h"
#include <iostream>

GameScreenView::GameScreenView(QWidget *parent)
{

        car = new CarItem();
        coinTimer = new QTimer();
        sceneTimer = new QTimer();
        accelerationTimer = new QTimer();
        scene = new QGraphicsScene();
        scoreItemGroup = new QGraphicsItemGroup();
        winLabel = new WinLabelItem(getDesktopHeight(), getDesktopWidth());

        upCarMovementIsBlocked = false;
        downCarMovementIsBlocked = false;
        sceneMovementSpeed = 5;
        sceneAcceleration = 100;
        coinsNumber = 20;
        coinPoints = 25;
        sceneTimerRate = 30;
        accelerationTimerRate = 1500;
        sceneLength = 12000;
        scoreLength = 4;
        coinVecIndex = 0;
        currentScore = 0;
        finalScore = 0;

        putCoins();
        putScoreCounter();

        sceneBackground.load(":/resource/img/GamePic.jpg");
        scene->addItem(scoreItemGroup);
        scene->addItem(car);
        for(int i=0; i<coinsNumber; i++)
            scene->addItem(coins[i]);
        scene->setSceneRect(0, 0, sceneLength, getDesktopHeight()-2);
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

GameScreenView::~GameScreenView(){

    delete car;
    delete coinTimer;
    delete sceneTimer;
    delete accelerationTimer;
    delete scoreItemGroup;
    delete winLabel;
    std::vector<CoinItem*>().swap(coins);
    std::vector<NumberItem*>().swap(scoreNumsVector);
    delete scene;

}

void GameScreenView::wheelEvent(QWheelEvent *event)
{

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
        case Qt::Key_Escape:
            emit escPressed();
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

int GameScreenView::getFinalScore()
{
    return finalScore;
}

void GameScreenView::setSceneLength(int len)
{
    sceneLength = len;
}

int GameScreenView::getSceneLength()
{
    return sceneLength;
}

void GameScreenView::putCoins()
{
    srand (time(0));

    int coinLocationInterval = sceneLength / (coinsNumber + 1);
    int intervalNumber = 1;

    for(int i=0; i<coinsNumber;i++){
        coins.push_back(new CoinItem());
        int x = rand() % coinLocationInterval + coinLocationInterval*intervalNumber;
        double y = rand() % getDesktopHeight()/2.8  + getDesktopHeight()/1.8 ;
        coins[i]->setPos(x, y);
        intervalNumber++;
    }

}

void GameScreenView::putScoreCounter() {

    if(scoreLength <= 0)
        return;

    int space = 70;

    for(int i = 0; i < scoreLength; i++){
        scoreNumsVector.push_back(new NumberItem());
        scene->addItem(scoreNumsVector[i]);
        scoreNumsVector[i]->setPos(space*i, 100);
        scoreItemGroup->addToGroup(scoreNumsVector[i]);
    }


    scoreItemGroup->setScale(0.4);
    scoreItemGroup->setPos(getDesktopWidth() - scoreNumsVector[0]->pixmap().width() * scoreLength / 2, -scoreNumsVector[0]->pixmap().height() / 4);
}

void GameScreenView::changeScoreCounter()
{
    if(currentScore >= 10000)
        return;

    int scoreIndex = scoreNumsVector.size()-1;

    for(int i = 10; i <= pow(10, scoreLength); i *= 10){

        switch ((currentScore % i) / (i/10)) {

        case 0:
            scoreNumsVector[scoreIndex]->setPixmap(QPixmap::fromImage(QImage(":/resource/img/number0.png")));
            break;
        case 1:
            scoreNumsVector[scoreIndex]->setPixmap(QPixmap::fromImage(QImage(":/resource/img/number1.png")));
            break;
        case 2:
            scoreNumsVector[scoreIndex]->setPixmap(QPixmap::fromImage(QImage(":/resource/img/number2.png")));
            break;
        case 3:
            scoreNumsVector[scoreIndex]->setPixmap(QPixmap::fromImage(QImage(":/resource/img/number3.png")));
            break;
        case 4:
            scoreNumsVector[scoreIndex]->setPixmap(QPixmap::fromImage(QImage(":/resource/img/number4.png")));
            break;
        case 5:
            scoreNumsVector[scoreIndex]->setPixmap(QPixmap::fromImage(QImage(":/resource/img/number5.png")));
            break;
        case 6:
            scoreNumsVector[scoreIndex]->setPixmap(QPixmap::fromImage(QImage(":/resource/img/number6.png")));
            break;
        case 7:
            scoreNumsVector[scoreIndex]->setPixmap(QPixmap::fromImage(QImage(":/resource/img/number7.png")));
            break;
        case 8:
            scoreNumsVector[scoreIndex]->setPixmap(QPixmap::fromImage(QImage(":/resource/img/number8.png")));
            break;
        case 9:
            scoreNumsVector[scoreIndex]->setPixmap(QPixmap::fromImage(QImage(":/resource/img/number9.png")));
            break;
        default:
            break;
        }

        scoreIndex--;
    }
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
    scoreItemGroup->setPos(mapToScene(QPoint(getDesktopWidth() - scoreNumsVector[0]->pixmap().width() * scoreLength / 2, -scoreNumsVector[0]->pixmap().height() / 4)));

    //check if car gets a coin
    std::vector<CoinItem*>::iterator it;
    for ( it = coins.begin(); it != coins.end(); it++){
        if((*it)->collidesWithItem(car)){

            currentScore += coinPoints;
            changeScoreCounter();
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



    //check borders of the road
    if(car->pos().y() > getDesktopHeight() - (car->pixmap().height()/4 + 10))
        downCarMovementIsBlocked = true;
    else
        downCarMovementIsBlocked = false;

    if(car->pos().y() < getDesktopHeight()/1.8)
        upCarMovementIsBlocked = true;
    else
        upCarMovementIsBlocked = false;


    //check end of the game condition
    if(car->pos().x() > sceneLength){

        sceneTimer->stop();
        accelerationTimer->stop();

        scene->addItem(winLabel);

        int winLocX = mapToScene(pos()).x()+getDesktopWidth()/2 - winLabel->pixmap().width() * (winLabel->scale() / 2);
        int winLocY = -winLabel->pixmap().height() * 2 ;

        winLabel->setPos(winLocX, winLocY);
        winLabel->animatedMoveToScenePos(winLocX, getDesktopHeight()/2 - winLabel->pixmap().height() * 2);

        finalScore = currentScore;

    }
}

