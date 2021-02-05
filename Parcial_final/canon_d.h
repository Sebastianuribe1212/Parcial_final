#ifndef CANON_D_H
#define CANON_D_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QKeyEvent>
#include <QList>

class canon_d:  public QObject, public QGraphicsItem
{
     Q_OBJECT
private:
    int posx, posy;
public:
     explicit canon_d(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    int getPosx() const;
    void setPosx(int value);
    int getPosy() const;
    void setPosy(int value);


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
};

#endif // CANON_D_H
