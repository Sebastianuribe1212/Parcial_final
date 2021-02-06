#ifndef LAUNCH_H
#define LAUNCH_H

#include <QObject>
#include <QTimer>
#include <QGraphicsView>
#include "lanzador.h"
#include "lanzador2.h"
class launch: public QGraphicsView
{
    Q_OBJECT
private:
    int XcanonOfensivo;
    int YcanonOfensivo;
    int XcanonDefensivo;
    int YcanonDefensivo;

    int opcion;
public:
    launch(QWidget * parent = 0);
    lanzador *lanzar;
    QTimer *timer;

    lanzador2 * lanzar2;
    int getXcanonOfensivo() const;
    void setXcanonOfensivo(int value);
    int getYcanonOfensivo() const;
    void setYcanonOfensivo(int value);
    int getXcanonDefensivo() const;
    void setXcanonDefensivo(int value);
    int getYcanonDefensivo() const;
    void setYcanonDefensivo(int value);

    int getOpcion() const;
    void setOpcion(int value);

private slots:
    void Actualizacion1();
};

#endif // LAUNCH_H
