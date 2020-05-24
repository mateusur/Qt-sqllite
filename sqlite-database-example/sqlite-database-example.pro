#-------------------------------------------------
#
# Project created by QtCreator 2014-12-07T19:36:39
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sqlite-database-example
TEMPLATE = app


SOURCES += main.cpp\
        katedra.cpp \
        kurs.cpp \
        kursy.cpp \
        mainwindow.cpp \
        prowadzacy.cpp \
        sala.cpp \
        student.cpp

HEADERS  += mainwindow.h \
    katedra.h \
    kurs.h \
    kursy.h \
    prowadzacy.h \
    sala.h \
    student.h

FORMS    += mainwindow.ui
