#-------------------------------------------------
#
# Project created by QtCreator 2015-05-08T15:57:23
#
#-------------------------------------------------

QT       += core gui
QT      += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = talk
TEMPLATE = app


SOURCES += main.cpp\
        talk.cpp \
    dialog.cpp

HEADERS  += talk.h \
    dialog.h

FORMS    += talk.ui \
    dialog.ui
