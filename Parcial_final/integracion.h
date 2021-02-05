#ifndef INTEGRACION_H
#define INTEGRACION_H

#include "lanzador.h"
#include "ingreso_datos.h"
#include <QObject>
#include <QTimer>
#include <QGraphicsView>
class integracion: public QGraphicsView
{
    Q_OBJECT
private:
    int XcanonOfensivo;
    int YcanonOfensivo;
    int XcanonDefensivo;
    int YcanonDefensivo;
public:
    Ingreso_datos * datos;
    explicit integracion(QWidget *parent = nullptr);

    QTimer *timer;



    int getXcanonOfensivo() const;
    void setXcanonOfensivo(int value);

    int getYcanonOfensivo() const;
    void setYcanonOfensivo(int value);

    int getXcanonDefensivo() const;
    void setXcanonDefensivo(int value);

    int getYcanonDefensivo() const;
    void setYcanonDefensivo(int value);

private slots:
    void Actualizacion1();


};

#endif // INTEGRACION_H
