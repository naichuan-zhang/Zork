#-------------------------------------------------
#
# Project created by QtCreator 2018-10-05T18:37:54
#
#-------------------------------------------------

#-------------------------------------------------
#
# Author: Naichuan Zhang
# Date: 05/10/2018
#
#-------------------------------------------------

QT       += core gui widgets
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Zork
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    exitdialog.cpp \
    custbutton.cpp \
    loadingwidget.cpp \
    setting.cpp \
    textticker.cpp \
    game.cpp \
    roledialog.cpp \
    background.cpp \
    room.cpp \
    item.cpp \
    logs.cpp \
    map.cpp \
    snake.cpp \
    tiger.cpp \
    stone.cpp \
    gold.cpp \
    help.cpp \
    mylabel.cpp \
    windialog.cpp

HEADERS += \
        mainwindow.h \
    exitdialog.h \
    custbutton.h \
    loadingwidget.h \
    setting.h \
    textticker.h \
    game.h \
    roledialog.h \
    background.h \
    room.h \
    item.h \
    logs.h \
    map.h \
    snake.h \
    tiger.h \
    stone.h \
    gold.h \
    help.h \
    mylabel.h \
    windialog.h

FORMS += \
        mainwindow.ui \
    exitdialog.ui \
    setting.ui \
    roledialog.ui \
    roledialog.ui \
    help.ui \
    windialog.ui

# RESET
QMAKE_CXXFLAGS += -std=gnu++11

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icon.qrc \
    images.qrc \
    buttons.qrc \
    game.qrc \
    music.qrc

RC_ICONS = "zork.ico"

DISTFILES += \
    license
