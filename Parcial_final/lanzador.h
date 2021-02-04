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

class lanzador: public QGraphicsView
{
    Q_OBJECT
public:
    lanzador(QWidget * parent = 0);
    QGraphicsScene * scene;
    canon_o * ofensivo;
};

#endif // LANZADOR_H
