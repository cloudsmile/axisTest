#-------------------------------------------------
#
# Project created by QtCreator 2018-03-30T10:09:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = axisTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    axistag.cpp \
    qcustomplot.cpp \
    tagaxis.cpp

HEADERS  += mainwindow.h \
    axistag.h \
    qcustomplot.h \
    tagaxis.h

FORMS    += mainwindow.ui
