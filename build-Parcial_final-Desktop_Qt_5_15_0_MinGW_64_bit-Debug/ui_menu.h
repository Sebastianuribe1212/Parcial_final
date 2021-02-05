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

    void setupUi(QWidget *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QString::fromUtf8("menu"));
        menu->setEnabled(true);
        menu->resize(400, 300);
        menu->setFocusPolicy(Qt::NoFocus);
        Ingresardatos = new QPushButton(menu);
        Ingresardatos->setObjectName(QString::fromUtf8("Ingresardatos"));
        Ingresardatos->setGeometry(QRect(160, 110, 80, 21));
        Ingresardatos->setFocusPolicy(Qt::NoFocus);
        pushButton = new QPushButton(menu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 170, 201, 21));
        pushButton->setFocusPolicy(Qt::NoFocus);

        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QWidget *menu)
    {
        menu->setWindowTitle(QCoreApplication::translate("menu", "Form", nullptr));
        Ingresardatos->setText(QCoreApplication::translate("menu", "Ingresar datos", nullptr));
        pushButton->setText(QCoreApplication::translate("menu", "Comienza simulaci\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
