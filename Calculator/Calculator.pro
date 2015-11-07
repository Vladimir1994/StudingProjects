TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    calculator.cpp

HEADERS += \
    sinfunctorone.h \
    sinfunctorthree.h \
    sinfunctortwo.h \
    context.h \
    functor.h \
    calculator.h

CONFIG += c++11
