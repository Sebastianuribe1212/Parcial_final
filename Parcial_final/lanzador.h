#ifndef LANZADOR_H
#define LANZADOR_H
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QTimer>
#include <QList>
#include <cmath>
#include <QList>
#include "canon_o.h"
#include "canon_d.h"
#include "balao.h"

class lanzador: public QGraphicsView
{
    Q_OBJECT
private:
    int XcanonOfensivo;
    int YcanonOfensivo;
    int XcanonDefensivo;
    int YcanonDefensivo;

    int t;
    int V0o;
    int angle;
public:
    lanzador(QWidget * parent = 0);
    QGraphicsScene * scene;
    QGraphicsView *view ;
    canon_o * ofensivo;
    canon_d *defensivo;
    //balaO * BalaO;
    QTimer *time;
    QList <int> angleoo1;
    QList <int> vooo1;
    QList <int> tiempo;


    float aux2 =0;
     balaO *prueba1;

    int getXcanonOfensivo() const;
    void setXcanonOfensivo(int value);
    int getYcanonOfensivo() const;
    void setYcanonOfensivo(int value);
    int getXcanonDefensivo() const;
    void setXcanonDefensivo(int value);
    int getYcanonDefensivo() const;
    void setYcanonDefensivo(int value);
    void grafica(int t,  int V0o, int angle );
    void grafica2(int t, int V0o, int angle );
    void grafica3(int t, int V0o, int angle );
    QList<balaO*> diez_bolas();

    QList<balaO*> balaOf= diez_bolas();
    QList<balaO*> balaOf2=diez_bolas();
    QList<balaO*> balaOf3=diez_bolas();



    int getAngle() const;
    void setAngle(int value);

    int getV0o() const;
    void setV0o(int value);

    int getT() const;
    void setT(int value);

private slots:
    void Actualizacion1();
    void Lanzamiento1();
    void grafica_fluida();

};

#endif // LANZADOR_H
