#ifndef COINITEM_H
#define COINITEM_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsItemAnimation>
#include <QPixmap>
#include <QtCore>
#include <QtGui>
#include <vector>
#include <string>


class CoinItem : public QGraphicsPixmapItem
{

public:
    CoinItem();
    std::vector<std::string> getCoinImageSources();
    int getCoinSpinningSpeed();

private:
    std::vector<std::string> coinImageSources;
    int coinSpinningSpeed;

    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};


#endif // COINITEM_H
