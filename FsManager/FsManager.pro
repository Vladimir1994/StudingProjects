TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    makedir.cpp \
    makepath.cpp \
    commandmanager.cpp \
    command.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    command.h \
    makedir.h \
    makepath.h \
    commandmanager.h \
    abstractfactory.h \
    factory.h

QMAKE_CXXFLAGS += -std=c++0x
CONFIG += c++11

