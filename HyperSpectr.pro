#-------------------------------------------------
#
# Project created by QtCreator 2015-11-25T10:55:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = HyperSpectr
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    HyperCube.cpp \
    ParseAviris.cpp \
    qcustomplot.cpp

HEADERS  += MainWindow.h \
    HyperCube.h \
    ParseAviris.h \
    qcustomplot.h

FORMS    += MainWindow.ui
