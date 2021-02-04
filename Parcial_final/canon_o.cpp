#include "canon_o.h"

canon_o::canon_o(QObject *parent): QObject(parent)
{
setPos(getPosx(),getPosy());
}

int canon_o::getPosy() const
{
    return posy;
}

void canon_o::setPosy(int value)
{
    posy = value;
}

int canon_o::getPosx() const
{
    return posx;
}

void canon_o::setPosx(int value)
{
    posx = value;
}
QRectF canon_o::boundingRect() const
{
    return QRectF(-1*50,-1*50,2*50,2*50);
}

void canon_o::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}
