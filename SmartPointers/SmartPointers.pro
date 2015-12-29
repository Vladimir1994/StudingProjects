TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    stringpointer.cpp \
    scopedptr.cpp \
    storage.cpp \
    sharedptr.cpp

HEADERS += \
    stringpointer.h \
    expression.h \
    scopedptr.h \
    storage.h \
    sharedptr.h

