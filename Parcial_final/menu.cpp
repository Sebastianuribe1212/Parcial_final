/*La gui menu, implementa la aquisisción de datos, además de dar paso a las escenas que nos muestran las pruebas con los parametros*/
#include "menu.h"
#include "ui_menu.h"
#include <QDebug>
#include <QMessageBox>
menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{
    timer = new QTimer;
    timer->start(80);
    ui->setupUi(this);

}

menu::~menu()
{
    delete ui;
}

void menu::on_Ingresardatos_clicked()
{

    datos->show();
    timer = new QTimer;
    timer->start(80);
    connect(timer,SIGNAL(timeout()), this,SLOT(Actualizacion1()));
}

//actualizacion es slot que recibe datos si salimos de la gui ingreso de datos al terminar el proceso
void menu::Actualizacion1()
{
    if(datos->getSalir()==true){
        this->setXcanonOfensivo(datos->getXcanonOfensivo());
        this->setYcanonOfensivo(datos->getYcanonOfensivo());

        this->setXcanonDefensivo(datos->getXcanonDefensivo());
        this->setYcanonDefensivo(datos->getYcanonDefensivo());
        qDebug()<<this->getXcanonOfensivo();
        qDebug()<<this->getYcanonOfensivo();
        qDebug()<<this->getXcanonDefensivo();
        qDebug()<<this->getYcanonDefensivo();

        datos->setSalir(false);
        this->setIngreso_datos(true);
         disconnect(timer,SIGNAL(timeout()), this,SLOT(Actualizacion1()));

         datos->hide();
    }
}

//boton para abrir la primera escena, hace set de la posición de los cañones
void menu::on_pushButton_clicked()
{
    if(this->getIngreso_datos() == true){
        lanza = new launch();
        lanza->setOpcion(1);
        lanza->setXcanonOfensivo(this->getXcanonOfensivo());
        lanza->setYcanonOfensivo(this->getYcanonOfensivo());
        lanza->setXcanonDefensivo(this->getXcanonDefensivo());
        lanza->setYcanonDefensivo(this->getYcanonDefensivo());

       // qDebug()<<"lanzador abierto";
    }


 else{
        QMessageBox::information(this,tr("ERROR"),tr("Ingresa los datos antes de seguir"));
    }

}

//boton para abrir la segunda escena, hace set de la posición de los cañones
void menu::on_pushButton_2_clicked()
{
    if(this->getIngreso_datos() == true){
        lanza = new launch();
        lanza->setOpcion(2);
        lanza->setXcanonOfensivo(this->getXcanonOfensivo());
        lanza->setYcanonOfensivo(this->getYcanonOfensivo());
        lanza->setXcanonDefensivo(this->getXcanonDefensivo());
        lanza->setYcanonDefensivo(this->getYcanonDefensivo());

       // qDebug()<<"lanzador abierto";
    }


 else{
        QMessageBox::information(this,tr("ERROR"),tr("Ingresa los datos antes de seguir"));
    }
}
//boton para abrir la tercera escena, hace set de la posición de los cañones
void menu::on_pushButton_3_clicked()
{
    if(this->getIngreso_datos() == true){
        lanza = new launch();
        lanza->setOpcion(3);
        lanza->setXcanonOfensivo(this->getXcanonOfensivo());
        lanza->setYcanonOfensivo(this->getYcanonOfensivo());
        lanza->setXcanonDefensivo(this->getXcanonDefensivo());
        lanza->setYcanonDefensivo(this->getYcanonDefensivo());

       // qDebug()<<"lanzador abierto";
    }


 else{
        QMessageBox::information(this,tr("ERROR"),tr("Ingresa los datos antes de seguir"));
    }
}

//boton para abrir la cuarta escena, hace set de la posición de los cañones
void menu::on_pushButton_4_clicked()
{
    if(this->getIngreso_datos() == true){
        lanza = new launch();
        lanza->setOpcion(4);
        lanza->setXcanonOfensivo(this->getXcanonOfensivo());
        lanza->setYcanonOfensivo(this->getYcanonOfensivo());
        lanza->setXcanonDefensivo(this->getXcanonDefensivo());
        lanza->setYcanonDefensivo(this->getYcanonDefensivo());

       // qDebug()<<"lanzador abierto";
    }


 else{
        QMessageBox::information(this,tr("ERROR"),tr("Ingresa los datos antes de seguir"));
    }
}


//creamos funciones de set y get para el funcionamiento
bool menu::getIngreso_datos() const
{
    return ingreso_datos;
}

void menu::setIngreso_datos(bool value)
{
    ingreso_datos = value;
}

int menu::getXcanonOfensivo() const
{
    return XcanonOfensivo;
}

void menu::setXcanonOfensivo(int value)
{
    XcanonOfensivo = value;
}

int menu::getYcanonOfensivo() const
{
    return YcanonOfensivo;
}

void menu::setYcanonOfensivo(int value)
{
    YcanonOfensivo = value;
}

int menu::getXcanonDefensivo() const
{
    return XcanonDefensivo;
}

void menu::setXcanonDefensivo(int value)
{
    XcanonDefensivo = value;
}

int menu::getYcanonDefensivo() const
{
    return YcanonDefensivo;
}

void menu::setYcanonDefensivo(int value)
{
    YcanonDefensivo = value;
}




