TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    number.cpp \
    binaryoperation.cpp \
    functioncall.cpp \
    variable.cpp \
    copysyntaxtree.cpp \
    foldconstants.cpp

HEADERS += \
    expression.h \
    transformer.h \
    scope.h \
    number.h \
    binaryoperation.h \
    functioncall.h \
    variable.h \
    copysyntaxtree.h \
    foldconstants.h

