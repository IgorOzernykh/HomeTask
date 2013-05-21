#-------------------------------------------------
#
# Project created by QtCreator 2013-04-11T17:17:39
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 2-8-1
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += console qtestlib


TEMPLATE = app


SOURCES += main.cpp \
    NothingToDelExc.cpp \
    EndOfSetExc.cpp

HEADERS += \
    Bag.h \
    AVLTree.h \
    TreeNode.h \
    NothingToDelExc.h \
    AVLTreeTest.h \
    BagTest.h \
    AVLTreeIteratorTest.h \
    EndOfSetExc.h \
    BagIteratorTest.h
