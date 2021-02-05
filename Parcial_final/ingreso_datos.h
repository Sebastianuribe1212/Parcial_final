#ifndef INGRESO_DATOS_H
#define INGRESO_DATOS_H

#include <QWidget>

namespace Ui {
class Ingreso_datos;
}

class Ingreso_datos : public QWidget
{
    Q_OBJECT

public:
    explicit Ingreso_datos(QWidget *parent = nullptr);
    ~Ingreso_datos();

private:
    Ui::Ingreso_datos *ui;
};

#endif // INGRESO_DATOS_H
