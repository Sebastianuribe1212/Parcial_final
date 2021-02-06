#ifndef BALAD_H
#define BALAD_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>


class balad:  public QObject, public QGraphicsItem
{
     Q_OBJECT
private:
    int posx, posy;
public:
     explicit balad(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;



    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    int getPosx() const;
    void setPosx(int value);
    int getPosy() const;
    void setPosy(int value);
};

#endif // BALAD_H
