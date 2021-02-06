//balaO bala ofensiva, creamos la bala y le damos atributos,color distinto al de la bala defensiva
#include "balad.h"
#include "balao.h"
balaO::balaO(QObject *parent): QObject(parent)
{
    //this->setPosx(950);
    //this->setPosy(550);
    setPos(getPosx(),getPosy());
}
//le damos el tamaño
QRectF balaO::boundingRect() const
{
    return QRectF(-25,-25,25,25);
}
//le damos el atributo del color
void balaO::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect().center(),4,4);
}

int balaO::getPosx() const
{
    return posx;
}

void balaO::setPosx(int value)
{
    posx = value;
}

int balaO::getPosy() const
{
    return posy;
}

void balaO::setPosy(int value)
{
    posy = value;
}

