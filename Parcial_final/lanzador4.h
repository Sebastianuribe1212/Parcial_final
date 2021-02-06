#ifndef LANZADOR4_H
#define LANZADOR4_H


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
#include "balad.h"

class lanzador4: public QGraphicsView
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
    lanzador4(QWidget * parent = 0);
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

    void dispDefensivos();
    QList<balaO*> diez_bolas();
    QList<balad*> diez_bolasDef();

    QList<balad*>balaDef=diez_bolasDef();

    QList<balaO*> balaOf= diez_bolas();

    int getAngle() const;
    void setAngle(int value);

    int getV0o() const;
    void setV0o(int value);

    int getT() const;
    void setT(int value);

private slots:
    void Actualizacion1();
    void Lanzamiento1();



};
#endif // LANZADOR4_H
