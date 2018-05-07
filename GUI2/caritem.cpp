#include "caritem.h"

CarItem::CarItem()
{
    movementSpeed = 10;
    setPixmap(QPixmap::fromImage(QImage(":/resource/img/Car.png")));
    setPos(200, 500);
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


