//gui que nos posibilita el ingreso de la posicion de los cañones
#include "ingreso_datos.h"
#include "ui_ingreso_datos.h"

Ingreso_datos::Ingreso_datos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ingreso_datos)
{
    ui->setupUi(this);
}

Ingreso_datos::~Ingreso_datos()
{
    delete ui;
}
//al presionar el boton nos guarda los datos para ser usados
void Ingreso_datos::on_IngresaDatos_clicked()
{
    int Xo,Yo,Xd,Yd;

    QString::number (Xo=ui->XcanonOfensivo->value());
    QString::number (Yo=ui->YcanonOfensivo->value());
    QString::number (Xd=ui->XcanonDefensivo->value());
    QString::number (Yd=ui->YcanonDefensivo->value());

    this->setXcanonOfensivo(Xo);
    this->setYcanonOfensivo(Yo);
    this->setXcanonDefensivo(Xd);
    this->setYcanonDefensivo(Yd);

    this->setSalir(true);
}

//funciones get y set
int Ingreso_datos::getYcanonDefensivo() const
{
    return YcanonDefensivo;
}

void Ingreso_datos::setYcanonDefensivo(int value)
{
    YcanonDefensivo = value;
}

int Ingreso_datos::getXcanonDefensivo() const
{
    return XcanonDefensivo;
}

void Ingreso_datos::setXcanonDefensivo(int value)
{
    XcanonDefensivo = value;
}

int Ingreso_datos::getYcanonOfensivo() const
{
    return YcanonOfensivo;
}

void Ingreso_datos::setYcanonOfensivo(int value)
{
    YcanonOfensivo = value;
}

int Ingreso_datos::getXcanonOfensivo() const
{
    return XcanonOfensivo;
}

void Ingreso_datos::setXcanonOfensivo(int value)
{
    XcanonOfensivo = value;
}

bool Ingreso_datos::getSalir() const
{
    return salir;
}

void Ingreso_datos::setSalir(bool value)
{
    salir = value;
}
