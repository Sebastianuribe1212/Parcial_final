#ifndef LANZADOR_H
#define LANZADOR_H
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QTimer>
#include <QList>
#include "canon_o.h"
#include "canon_d.h"

class lanzador: public QGraphicsView
{
    Q_OBJECT
private:
    int XcanonOfensivo;
    int YcanonOfensivo;
    int XcanonDefensivo;
    int YcanonDefensivo;
public:
    lanzador(QWidget * parent = 0);
    QGraphicsScene * scene;
    canon_o * ofensivo;
    canon_d *defensivo;

    QTimer *time;



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
        void Lanzamiento1();
};

#endif // LANZADOR_H
