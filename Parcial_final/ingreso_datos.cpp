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

QString Ingreso_datos::getXcanonOfensivo() const
{
    return XcanonOfensivo;
}

void Ingreso_datos::setXcanonOfensivo(const QString &value)
{
    XcanonOfensivo = value;
}

QString Ingreso_datos::getYcanonOfensivo() const
{
    return YcanonOfensivo;
}

void Ingreso_datos::setYcanonOfensivo(const QString &value)
{
    YcanonOfensivo = value;
}

QString Ingreso_datos::getXcanonDefensivo() const
{
    return XcanonDefensivo;
}

void Ingreso_datos::setXcanonDefensivo(const QString &value)
{
    XcanonDefensivo = value;
}

QString Ingreso_datos::getYcanonDefensivo() const
{
    return YcanonDefensivo;
}

void Ingreso_datos::setYcanonDefensivo(const QString &value)
{
    YcanonDefensivo = value;
}

void Ingreso_datos::on_IngresaDatos_clicked()
{
    //QString Xo,Yo,Xd,Yd;

    QString Xo=ui->XcanonOfensivo->text();
    QString Yo=ui->YcanonOfensivo->text();
    QString Xd=ui->XcanonDefensivo->text();
    QString Yd=ui->YcanonDefensivo->text();

    this->setXcanonOfensivo(Xo);
    this->setYcanonOfensivo(Yo);
    this->setXcanonDefensivo(Xd);
    this->setYcanonDefensivo(Yd);

    this->setSalir(true);
}

bool Ingreso_datos::getSalir() const
{
    return salir;
}

void Ingreso_datos::setSalir(bool value)
{
    salir = value;
}
