#include "winlabelitem.h"

WinLabelItem::WinLabelItem(int desktopHeight, int desktopWidth)
{
    setScale(1.5);
    setPixmap(QPixmap::fromImage(QImage(":/resource/img/winLabel.png")));

}

void WinLabelItem::animatedMoveToScenePos(int x, int y){

    QTimeLine *timer = new QTimeLine(1500);
    timer->setFrameRange(0, 100);

    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
    animation->setItem(this);
    animation->setTimeLine(timer);
    animation->setPosAt(1, QPointF(x, y));

    timer->start();
}
