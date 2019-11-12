#-------------------------------------------------
#
# Project created by QtCreator 2019-08-29T05:40:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ouk
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -L"C:\SFML-2.5.1\lib"
LIBS += -L"C:\SFML-2.5.1\bin"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "C:\SFML-2.5.1\include"
DEPENDPATH += "C:\SFML-2.5.1\include"

CONFIG += c++11

SOURCES += \
        accessory.cpp \
        krorla.cpp \
        main.cpp \
        mainwindow.cpp \
        mouse.cpp \
        music.cpp \
        oukpieceway.cpp \
        sound.cpp

HEADERS += \
        accessory.h \
        krorla.h \
        mainwindow.h \
        mouse.h \
        music.h \
        oukpieceway.h \
        sound.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
