QT += core
QT += testlib

TARGET = Polynomial
CONFIG += console
CONFIG -= app_bundle
CONFIG += console c++11

TEMPLATE = app

SOURCES += main.cpp \
    polynomial.cpp

HEADERS += \
    polynomial.h

