#-------------------------------------------------
#
# Project created by QtCreator 2017-04-11T14:58:40
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += -std=c++11
TARGET = MFC_APP
TEMPLATE = app

LIBS += -L/usr/include/boost -lboost_system
LIBS += -lpthread
LIBS += -lboost_thread
LIBS += -lboost_filesystem


SOURCES += main.cpp\
        mfcui.cpp\
    ../../alicat/alicat.cpp \
    ../../serial/serialcomm.cpp

HEADERS  += mfcui.h \
    ../../alicat/alicat.h \
    ../../serial/serialcomm.h \
    ../../general_definitions.h \
    ../../data.h

FORMS    += mfcui.ui
