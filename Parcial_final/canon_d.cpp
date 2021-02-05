#include "canon_d.h"


canon_d::canon_d(QObject *parent): QObject(parent)
{
    //this->setPosx(950);
    //this->setPosy(550);
setPos(getPosx(),getPosy());
}

int canon_d::getPosy() const
{
    return posy;
}

void canon_d::setPosy(int value)
{
    posy = value;
}

int canon_d::getPosx() const
{
    return posx;
}

void canon_d::setPosx(int value)
{
    posx = value;
}
QRectF canon_d::boundingRect() const
{
    return QRectF(-1*50,-1*50,2*50,2*50);
}

void canon_d::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}
