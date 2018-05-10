#ifndef WINLABELITEM_H
#define WINLABELITEM_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsItemAnimation>
#include <QPixmap>
#include <QtCore>
#include <QtGui>
#include <vector>
#include <string>


class WinLabelItem : public QGraphicsPixmapItem
{

public:
    WinLabelItem(int desktopHeight, int desktopWidth);
    virtual ~WinLabelItem();
    void animatedMoveToScenePos(int x, int y);

private:
    QTimeLine *timer;
    QGraphicsItemAnimation *animation;
};

#endif // WINLABELITEM_H
