QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canon_d.cpp \
    canon_o.cpp \
    ingreso_datos.cpp \
    lanzador.cpp \
    launch.cpp \
    main.cpp \
    menu.cpp

HEADERS += \
    canon_d.h \
    canon_o.h \
    ingreso_datos.h \
    lanzador.h \
    launch.h \
    menu.h

FORMS += \
    ingreso_datos.ui \
    menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
