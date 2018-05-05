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
    void setMovementSpeed(double speed);
    double getMovementSpeed();

private:
    double movementSpeed;
   // void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // CARITEM_H
