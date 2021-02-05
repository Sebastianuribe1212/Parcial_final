/********************************************************************************
** Form generated from reading UI file 'ingreso_datos.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INGRESO_DATOS_H
#define UI_INGRESO_DATOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ingreso_datos
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *XcanonOfensivo;
    QLineEdit *YcanonOfensivo;
    QLineEdit *XcanonDefensivo;
    QLineEdit *YcanonDefensivo;
    QPushButton *IngresaDatos;

    void setupUi(QWidget *Ingreso_datos)
    {
        if (Ingreso_datos->objectName().isEmpty())
            Ingreso_datos->setObjectName(QString::fromUtf8("Ingreso_datos"));
        Ingreso_datos->resize(400, 300);
        label = new QLabel(Ingreso_datos);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 131, 16));
        label_2 = new QLabel(Ingreso_datos);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 30, 131, 16));
        label_3 = new QLabel(Ingreso_datos);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 140, 131, 16));
        label_4 = new QLabel(Ingreso_datos);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(240, 140, 131, 16));
        XcanonOfensivo = new QLineEdit(Ingreso_datos);
        XcanonOfensivo->setObjectName(QString::fromUtf8("XcanonOfensivo"));
        XcanonOfensivo->setGeometry(QRect(50, 50, 113, 21));
        YcanonOfensivo = new QLineEdit(Ingreso_datos);
        YcanonOfensivo->setObjectName(QString::fromUtf8("YcanonOfensivo"));
        YcanonOfensivo->setGeometry(QRect(50, 170, 113, 21));
        XcanonDefensivo = new QLineEdit(Ingreso_datos);
        XcanonDefensivo->setObjectName(QString::fromUtf8("XcanonDefensivo"));
        XcanonDefensivo->setGeometry(QRect(240, 50, 113, 21));
        YcanonDefensivo = new QLineEdit(Ingreso_datos);
        YcanonDefensivo->setObjectName(QString::fromUtf8("YcanonDefensivo"));
        YcanonDefensivo->setGeometry(QRect(240, 170, 113, 21));
        IngresaDatos = new QPushButton(Ingreso_datos);
        IngresaDatos->setObjectName(QString::fromUtf8("IngresaDatos"));
        IngresaDatos->setGeometry(QRect(160, 210, 80, 21));

        retranslateUi(Ingreso_datos);

        QMetaObject::connectSlotsByName(Ingreso_datos);
    } // setupUi

    void retranslateUi(QWidget *Ingreso_datos)
    {
        Ingreso_datos->setWindowTitle(QCoreApplication::translate("Ingreso_datos", "Form", nullptr));
        label->setText(QCoreApplication::translate("Ingreso_datos", "Posici\303\263n x canon ofensivo", nullptr));
        label_2->setText(QCoreApplication::translate("Ingreso_datos", "Posici\303\263n x canon ofensivo", nullptr));
        label_3->setText(QCoreApplication::translate("Ingreso_datos", "Posici\303\263n x canon defensivo", nullptr));
        label_4->setText(QCoreApplication::translate("Ingreso_datos", "Posici\303\263n y canon defensivo", nullptr));
        IngresaDatos->setText(QCoreApplication::translate("Ingreso_datos", "Ingresar datos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ingreso_datos: public Ui_Ingreso_datos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INGRESO_DATOS_H
