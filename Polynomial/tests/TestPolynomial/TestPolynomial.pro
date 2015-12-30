QT += core
QT -= gui

CONFIG += console
CONFIG -= app_bundle
CONFIG += testlib
CONFIG += console c++11
QT += testlib

TEMPLATE = app

HEADERS += ../../polynomial.h

SOURCES += \
    testpolynomial.cpp \
    ../../polynomial.cpp


