#ifndef CANON_O_H
#define CANON_O_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QKeyEvent>
#include <QList>

class canon_o:  public QObject, public QGraphicsItem
{
     Q_OBJECT
private:
    int posx, posy;
public:
     explicit canon_o(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    int getPosx() const;
    void setPosx(int value);
    int getPosy() const;
    void setPosy(int value);


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

};

#endif // CANON_O_H
