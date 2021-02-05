#include "lanzador.h"
#include <QDebug>


lanzador::lanzador(QWidget * parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,600);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,600);
    setWindowTitle("Batalla");


    ofensivo = new canon_o();
    scene->addItem(ofensivo);

    defensivo = new canon_d();
    scene->addItem(defensivo);
    time = new QTimer;
    time->start(80);
    connect(time,SIGNAL(timeout()), this,SLOT(Actualizacion1()));
    show();
}



void lanzador::Actualizacion1()
{

    ofensivo->setPosx(this->getXcanonOfensivo());
    ofensivo->setPosy(this->getYcanonOfensivo());
    ofensivo->setPos(this->getXcanonOfensivo(),this->getYcanonOfensivo());

    defensivo->setPosx(this->getXcanonDefensivo());
    defensivo->setPosy(this->getYcanonDefensivo());
    defensivo->setPos(this->getXcanonDefensivo(),this->getYcanonDefensivo());
    qDebug()<<"Datos ingresados en launcher";
    //disconnect(timer,SIGNAL(timeout()), this,SLOT(Actualizacion1()));
}

void lanzador::Lanzamiento1()
{

}

int lanzador::getXcanonOfensivo() const
{
    return XcanonOfensivo;
}

void lanzador::setXcanonOfensivo(int value)
{
    XcanonOfensivo = value;
}

int lanzador::getYcanonOfensivo() const
{
    return YcanonOfensivo;
}

void lanzador::setYcanonOfensivo(int value)
{
    YcanonOfensivo = value;
}

int lanzador::getXcanonDefensivo() const
{
    return XcanonDefensivo;
}

void lanzador::setXcanonDefensivo(int value)
{
    XcanonDefensivo = value;
}

int lanzador::getYcanonDefensivo() const
{
    return YcanonDefensivo;
}

void lanzador::setYcanonDefensivo(int value)
{
    YcanonDefensivo = value;
}


