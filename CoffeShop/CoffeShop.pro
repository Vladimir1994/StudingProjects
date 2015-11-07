TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    coffe.cpp \
    latte.cpp \
    espresso.cpp \
    decoratorchocolate.cpp \
    decoratormilk.cpp \
    iproduct.cpp \
    idrink.cpp \
    idecorator.cpp
CONFIG += c++11

HEADERS += \
    iproduct.h \
    coffe.h \
    latte.h \
    espresso.h \
    decoratorchocolate.h \
    decoratormilk.h \
    idrink.h \
    idecorator.h

