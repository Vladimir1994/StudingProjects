#-------------------------------------------------
#
# Project created by QtCreator 2015-08-04T17:44:11
#
#-------------------------------------------------

QT       += core gui
QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Graphics
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    model.cpp \
    plotholder.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    model.h \
    iobserver.h \
    plotholder.h \
    generator.h \
    generatortwo.h \
    generatorone.h \
    generatorthree.h

FORMS    += mainwindow.ui
CONFIG += c++11
