#-------------------------------------------------
#
# Project created by QtCreator 2013-04-07T19:53:30
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 2-7-2
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += console qtestlib

TEMPLATE = app


SOURCES += main.cpp \
    NothingToDelExc.cpp \
    AlreadyExistExc.cpp

HEADERS += \
    NothingToDelExc.h \
    ListTest.h \
    ListElement.h \
    AlreadyExistExc.h \
    UniqueList.h
