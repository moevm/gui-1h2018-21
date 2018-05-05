#include "gamescreenview.h"

GameScreenView::GameScreenView(QWidget *parent)
{

        car = new CarItem();
        coinTimer = new QTimer();
        sceneTimer = new QTimer();
        scene = new QGraphicsScene();


        for(int i=0; i<coinsNumber;i++){
            coins.push_back(new CoinItem());
            coins[i]->setPos(i*100, 500);
        }


        sceneMovementSpeed = 10;
        coinsNumber = 3;
        sceneTimerRate = 200;
        sceneLenght = 6000;
        coinVecIndex = 0;
        currentScore = 0;

        sceneBackground.load(":/resource/img/GamePic.jpg");

        scene->addItem(car);
        for(int i=0; i<coinsNumber; i++)
            scene->addItem(coins[i]);

        scene->setSceneRect(0, 0, sceneLenght, 700);
        scene->setBackgroundBrush(sceneBackground.scaledToHeight(scene->height()));

        this->setScene(scene);
        this->setTransformationAnchor(NoAnchor);
        this->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
        this->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );

        if(!coins.empty())
            coinTimer->setInterval(coins[0]->getCoinSpinningSpeed());


        sceneTimer->setInterval(sceneTimerRate);


        connect(coinTimer, SIGNAL(timeout()), this, SLOT(updateCoinImage()));
        connect(sceneTimer, SIGNAL(timeout()), this, SLOT(updateSceneState()));


        coinTimer->start();
        sceneTimer->start();


}



void GameScreenView::keyPressEvent(QKeyEvent *keyEvent){

    switch (keyEvent->key()) {
        case Qt::Key_Down:
            car->moveBy(0, car->getMovementSpeed());
            break;
        case Qt::Key_Up:
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

void GameScreenView::updateSceneState()
{

    std::vector<CoinItem*>::iterator it;
    for ( it = coins.begin(); it != coins.end(); it++){
        if((*it)->collidesWithItem(car)){
            currentScore += coinPoints;
            scene->removeItem(*it);
            coinsNumber--;
            coins.erase(it);
            it = coins.begin();
        }

    }
}

