QT += core
QT -= gui


QMAKE_CXXFLAGS += -std=c++11
TARGET = testing_functionality
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

