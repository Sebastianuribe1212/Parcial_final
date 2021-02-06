/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QPushButton *Ingresardatos;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QString::fromUtf8("menu"));
        menu->setEnabled(true);
        menu->resize(400, 300);
        menu->setFocusPolicy(Qt::NoFocus);
        Ingresardatos = new QPushButton(menu);
        Ingresardatos->setObjectName(QString::fromUtf8("Ingresardatos"));
        Ingresardatos->setGeometry(QRect(170, 240, 80, 21));
        Ingresardatos->setFocusPolicy(Qt::NoFocus);
        pushButton = new QPushButton(menu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 30, 241, 31));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton_2 = new QPushButton(menu);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 70, 241, 31));
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        pushButton_3 = new QPushButton(menu);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(60, 120, 301, 31));
        pushButton_3->setFocusPolicy(Qt::NoFocus);
        pushButton_4 = new QPushButton(menu);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(60, 160, 301, 31));
        pushButton_4->setFocusPolicy(Qt::NoFocus);

        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QWidget *menu)
    {
        menu->setWindowTitle(QCoreApplication::translate("menu", "Form", nullptr));
        Ingresardatos->setText(QCoreApplication::translate("menu", "Ingresar datos", nullptr));
        pushButton->setText(QCoreApplication::translate("menu", "3 disp. ofensivos comprometen a defensivo", nullptr));
        pushButton_2->setText(QCoreApplication::translate("menu", "3 disp. defensivos comprometen a ofensivo", nullptr));
        pushButton_3->setText(QCoreApplication::translate("menu", "Dado disp. ofensivo generar disp ofensivos (sin restricciones)", nullptr));
        pushButton_4->setText(QCoreApplication::translate("menu", "Dado disp. ofensivo generar disp ofensivos (con restricciones)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
