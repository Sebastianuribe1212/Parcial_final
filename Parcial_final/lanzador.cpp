#include "lanzador.h"

lanzador::lanzador(QWidget * parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,600);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,600);
    setWindowTitle("Batalla");

    ofensivo = new canon_o();
    ofensivo->setPosx(0);
    ofensivo->setPosy(550);
    ofensivo->setPos(0,550);
    ofensivo->setFlag(QGraphicsItem::ItemIsFocusable, true);
    scene->addItem(ofensivo);
    scene->setFocusItem(ofensivo);

}
