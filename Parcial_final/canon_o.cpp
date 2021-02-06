//dibuja un circulo en la posicion dada por el usuario de color azul representando el cañon
#include "canon_o.h"

canon_o::canon_o(QObject *parent): QObject(parent)
{

    // this->setPosx(50);
    //this->setPosy(550);
   // setPos(getPosx(),getPosy());
}


QRectF canon_o::boundingRect() const
{
    return QRectF(-1*50,-1*50,2*50,2*50);
}
//damos atributo de color
void canon_o::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

float canon_o::getPosx() const
{
    return posx;
}

void canon_o::setPosx(float value)
{
    posx = value;
}

float canon_o::getPosy() const
{
    return posy;
}

void canon_o::setPosy(float value)
{
    posy = value;
}
