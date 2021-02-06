#include "launch.h"
#include <QDebug>
int launch::getOpcion() const
{
    return opcion;
}

void launch::setOpcion(int value)
{
    opcion = value;
}

launch::launch(QWidget * parent)
{

    timer = new QTimer;
    timer->start(80);

    connect(timer,SIGNAL(timeout()), this,SLOT(Actualizacion1()));
}

void launch::Actualizacion1()
{
    if(this->getOpcion() ==1){
        lanzar = new lanzador();
        lanzar->show();
        lanzar->setXcanonOfensivo(this->getXcanonOfensivo());
        lanzar->setYcanonOfensivo(this->getYcanonOfensivo());

        lanzar->setXcanonDefensivo(this->getXcanonDefensivo());
        lanzar->setYcanonDefensivo(this->getYcanonDefensivo());
    }
    else if(this->getOpcion()==2){
        lanzar2 = new lanzador2();
        lanzar2->show();
        lanzar2->setXcanonOfensivo(this->getXcanonOfensivo());
        lanzar2->setYcanonOfensivo(this->getYcanonOfensivo());

        lanzar2->setXcanonDefensivo(this->getXcanonDefensivo());
        lanzar2->setYcanonDefensivo(this->getYcanonDefensivo());
    }
    timer->stop();
   // qDebug()<<"Datos ingresados en launch";
    disconnect(timer,SIGNAL(timeout()), this,SLOT(Actualizacion1()));
}

int launch::getXcanonOfensivo() const
{
    return XcanonOfensivo;
}

void launch::setXcanonOfensivo(int value)
{
    XcanonOfensivo = value;
}

int launch::getYcanonOfensivo() const
{
    return YcanonOfensivo;
}

void launch::setYcanonOfensivo(int value)
{
    YcanonOfensivo = value;
}

int launch::getXcanonDefensivo() const
{
    return XcanonDefensivo;
}

void launch::setXcanonDefensivo(int value)
{
    XcanonDefensivo = value;
}

int launch::getYcanonDefensivo() const
{
    return YcanonDefensivo;
}

void launch::setYcanonDefensivo(int value)
{
    YcanonDefensivo = value;
}

