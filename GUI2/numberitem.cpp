#include "numberitem.h"

NumberItem::NumberItem()
{
    setPixmap(QPixmap::fromImage(QImage(":/resource/img/number0.png")));
    setPos(200,200);
}

NumberItem::~NumberItem()
{

}
