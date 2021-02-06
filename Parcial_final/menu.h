#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "ingreso_datos.h"
#include "lanzador.h"
#include "launch.h"
#include <QGraphicsScene>
#include <QGraphicsView>
namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT


public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

    QTimer *timer;
    launch *lanza;
    Ingreso_datos *datos= new Ingreso_datos(0);;

    int getXcanonOfensivo() const;
    void setXcanonOfensivo(int value);

    int getYcanonOfensivo() const;
    void setYcanonOfensivo(int value);

    int getXcanonDefensivo() const;
    void setXcanonDefensivo(int value);

    int getYcanonDefensivo() const;
    void setYcanonDefensivo(int value);

    bool getIngreso_datos() const;
    void setIngreso_datos(bool value);

private slots:
    void on_Ingresardatos_clicked();

    void Actualizacion1();

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::menu *ui;
    bool ingreso_datos = false;
    int XcanonOfensivo;
    int YcanonOfensivo;
    int XcanonDefensivo;
    int YcanonDefensivo;
};

#endif // MENU_H
