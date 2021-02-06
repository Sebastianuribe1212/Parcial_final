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
    float posx, posy;
public:
     explicit canon_o(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;




    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

    float getPosx() const;
    void setPosx(float value);
    float getPosy() const;
    void setPosy(float value);
};

#endif // CANON_O_H
