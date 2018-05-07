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
    void animatedMoveToScenePos(int x, int y);

private:

};

#endif // WINLABELITEM_H
