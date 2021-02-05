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
