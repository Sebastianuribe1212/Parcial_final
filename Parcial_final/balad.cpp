//balad bala defensiva, creamos la bala y le damos atributos,color distinto al de la bala ofensiva
#include "balad.h"

balad::balad(QObject *parent): QObject(parent)
{
    //this->setPosx(950);
    //this->setPosy(550);
    setPos(getPosx(),getPosy());
}
//le damos el tamaño
QRectF balad::boundingRect() const
{
    return QRectF(-25,-25,25,25);
}
//le damos el atributo del color
void balad::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect().center(),4,4);
}

int balad::getPosx() const
{
    return posx;
}

void balad::setPosx(int value)
{
    posx = value;
}

int balad::getPosy() const
{
    return posy;
}

void balad::setPosy(int value)
{
    posy = value;
}
