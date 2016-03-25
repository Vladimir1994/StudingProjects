QT += core
QT += testlib

TARGET = Polynomial
CONFIG += console
CONFIG -= app_bundle
CONFIG += console c++11

TEMPLATE = app

HEADERS += \
    polynomial.h

SOURCES += \
    main.cpp \
    polynomial.cpp


