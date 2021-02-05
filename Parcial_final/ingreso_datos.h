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

    QString getXcanonOfensivo() const;
    void setXcanonOfensivo(const QString &value);

    QString getYcanonOfensivo() const;
    void setYcanonOfensivo(const QString &value);

    QString getXcanonDefensivo() const;
    void setXcanonDefensivo(const QString &value);

    QString getYcanonDefensivo() const;
    void setYcanonDefensivo(const QString &value);

    bool getSalir() const;
    void setSalir(bool value);

private slots:
    void on_IngresaDatos_clicked();

private:
    Ui::Ingreso_datos *ui;
    QString XcanonOfensivo;
    QString YcanonOfensivo;
    QString XcanonDefensivo;
    QString YcanonDefensivo;

    bool salir=false;
};

#endif // INGRESO_DATOS_H
