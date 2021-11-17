#-------------------------------------------------
#
# Project created by QtCreator 2016-09-17T08:38:49
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += serialport




greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test

TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    misc.cpp \
    rfidtcpsocket.cpp \
    rfiddata.cpp

HEADERS  += mainwindow.h \
    misc.h \
    ui_dialog.h \
    rfidtcpsocket.h \
    rfiddata.h

FORMS    += mainwindow.ui \
    dialog.ui
