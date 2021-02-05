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



    bool getSalir() const;
    void setSalir(bool value);

    int getXcanonOfensivo() const;
    void setXcanonOfensivo(int value);

    int getYcanonOfensivo() const;
    void setYcanonOfensivo(int value);

    int getXcanonDefensivo() const;
    void setXcanonDefensivo(int value);

    int getYcanonDefensivo() const;
    void setYcanonDefensivo(int value);

private slots:
    void on_IngresaDatos_clicked();

private:
    Ui::Ingreso_datos *ui;
    int XcanonOfensivo;
    int YcanonOfensivo;
    int XcanonDefensivo;
    int YcanonDefensivo;

    bool salir=false;
};

#endif // INGRESO_DATOS_H
