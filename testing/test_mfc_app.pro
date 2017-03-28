#-------------------------------------------------
#
# Project created by QtCreator 2017-03-17T10:52:50
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = test_mfc_app
TEMPLATE = app

LIBS += -L/usr/include/boost -lboost_system
LIBS += -lpthread
LIBS += -lboost_thread
LIBS += -lboost_filesystem


SOURCES += main.cpp\
        mainwindow.cpp \
    ../serial/serial.cpp \
    ../alicat/alicat.cpp

HEADERS  += mainwindow.h \
    ../serial/serial.h \
    ../alicat/alicat.h

FORMS    += mainwindow.ui
