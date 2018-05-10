#include "winlabelitem.h"

WinLabelItem::WinLabelItem(int desktopHeight, int desktopWidth)
{

    timer = new QTimeLine(1500);
    animation = new QGraphicsItemAnimation;
    setScale(1.5);
    setPixmap(QPixmap::fromImage(QImage(":/resource/img/winLabel.png")));

}

WinLabelItem::~WinLabelItem()
{
    delete timer;
    delete animation;
}

void WinLabelItem::animatedMoveToScenePos(int x, int y){

    timer->setFrameRange(0, 100);
    animation->setItem(this);
    animation->setTimeLine(timer);
    animation->setPosAt(1, QPointF(x, y));

    timer->start();
}
