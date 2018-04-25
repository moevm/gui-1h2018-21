#include "gamescreenview.h"
#include "iostream"


GameScreenView::GameScreenView(QWidget *parent)
{

        pixmapCar = new QGraphicsPixmapItem(QPixmap::fromImage(QImage(":/resource/img/Car.png")));
        pixmapCar->setScale(0.3);

        scene = new QGraphicsScene();
        scene->setSceneRect(this->width()/2, 0, this->width(), this->height());
        this->setScene(scene);
        std::cout << pos().x() << ", " << pos().y() << std::endl;
        scene->addItem(pixmapCar);

}

void GameScreenView::keyPressEvent(QKeyEvent *keyEvent){

    switch (keyEvent->key()) {
        case Qt::Key_Down:
            pixmapCar->moveBy(0, 10);
            break;
        case Qt::Key_Up:
            pixmapCar->moveBy(0, -10);
            break;
        default:
            break;
    }
}


GameScreenView::~GameScreenView(){

}
