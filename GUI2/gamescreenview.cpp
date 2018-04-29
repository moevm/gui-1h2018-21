#include "gamescreenview.h"


GameScreenView::GameScreenView(QWidget *parent)
{
        car = new CarItem();
        scene = new QGraphicsScene();
        sceneLenght = 6000;

        sceneBackground.load(":/resource/img/GamePic.jpg");

        scene->addItem(car);
        scene->setSceneRect(0, 0, sceneLenght, getDesktopHeight());

        scene->setBackgroundBrush(sceneBackground.scaledToHeight(scene->height()));


        this->setScene(scene);


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
