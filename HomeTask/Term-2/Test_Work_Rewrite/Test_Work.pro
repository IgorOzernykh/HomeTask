#-------------------------------------------------
#
# Project created by QtCreator 2013-05-14T13:43:23
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Test_Work
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += qtestlib

TEMPLATE = app


SOURCES += main.cpp \
    QueueIsEmptyExc.cpp

HEADERS += \
    PriorityQueue.h \
    QueueElement.h \
    QueueIsEmptyExc.h \
    PriorityQueueTest.h
