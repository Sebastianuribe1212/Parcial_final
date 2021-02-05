#include "integracion.h"

integracion::integracion(QWidget *parent)
{
    datos = new Ingreso_datos();
    datos->show();
    timer = new QTimer;
    timer->start(80);
    connect(timer,SIGNAL(timeout()), this,SLOT(Actualizacion1()));
}

void integracion::Actualizacion1()
{
    if(datos->getSalir()==true){
        this->setXcanonOfensivo(datos->getXcanonOfensivo());
        this->setYcanonOfensivo(datos->getYcanonOfensivo());

        this->setXcanonDefensivo(datos->getXcanonDefensivo());
        this->setYcanonDefensivo(datos->getYcanonDefensivo());

        datos->hide();
    }
}


int integracion::getXcanonOfensivo() const
{
    return XcanonOfensivo;
}

void integracion::setXcanonOfensivo(int value)
{
    XcanonOfensivo = value;
}

int integracion::getYcanonOfensivo() const
{
    return YcanonOfensivo;
}

void integracion::setYcanonOfensivo(int value)
{
    YcanonOfensivo = value;
}

int integracion::getXcanonDefensivo() const
{
    return XcanonDefensivo;
}

void integracion::setXcanonDefensivo(int value)
{
    XcanonDefensivo = value;
}

int integracion::getYcanonDefensivo() const
{
    return YcanonDefensivo;
}

void integracion::setYcanonDefensivo(int value)
{
    YcanonDefensivo = value;
}
