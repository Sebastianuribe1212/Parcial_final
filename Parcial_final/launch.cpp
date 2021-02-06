/*la clase launch agrupa las escenas para ser lanzadas con su configuracion dependiendo
   de lo que el usuario escoja en el menu.
*/
#include "launch.h"
#include <QDebug>


launch::launch(QWidget * parent)
{
    //iniciamos el slot que me permite abrir las escenas
    timer = new QTimer;
    timer->start(80);

    connect(timer,SIGNAL(timeout()), this,SLOT(Actualizacion1()));
}


//dependiendo del boton presionado por el usuario se selecciona la escena para ser mostrada
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
    else if(this->getOpcion()==3){
        lanzar3 = new lanzador3();
        lanzar3->show();
        lanzar3->setXcanonOfensivo(this->getXcanonOfensivo());
        lanzar3->setYcanonOfensivo(this->getYcanonOfensivo());

        lanzar3->setXcanonDefensivo(this->getXcanonDefensivo());
        lanzar3->setYcanonDefensivo(this->getYcanonDefensivo());
    }
    else if(this->getOpcion()==4){
        lanzar4 = new lanzador4();
        lanzar4->show();
        lanzar4->setXcanonOfensivo(this->getXcanonOfensivo());
        lanzar4->setYcanonOfensivo(this->getYcanonOfensivo());

        lanzar4->setXcanonDefensivo(this->getXcanonDefensivo());
        lanzar4->setYcanonDefensivo(this->getYcanonDefensivo());
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
int launch::getOpcion() const
{
    return opcion;
}

void launch::setOpcion(int value)
{
    opcion = value;
}
