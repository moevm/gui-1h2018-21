#include "caritem.h"

CarItem::CarItem()
{
    movementSpeed = 10;
    setPixmap(QPixmap::fromImage(QImage(":/resource/img/Car.png")));
    setScale(0.25);
}



void CarItem::setMovementSpeed(double speed)
{
    movementSpeed = speed;
}

double CarItem::getMovementSpeed()
{
    return movementSpeed;
}


