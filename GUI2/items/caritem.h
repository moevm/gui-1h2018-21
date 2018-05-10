#ifndef CARITEM_H
#define CARITEM_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QtCore>
#include <QtGui>

class CarItem : public QGraphicsPixmapItem
{

public:
    CarItem();
    virtual ~CarItem();
    void setMovementSpeed(double speed);
    double getMovementSpeed();

private:
    double movementSpeed;

};

#endif // CARITEM_H
