#-------------------------------------------------
#
# Project created by QtCreator 2013-04-01T14:43:05
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 261
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += console qtestlib

TEMPLATE = app


SOURCES += main.cpp \
    Tree.cpp \
    OperatorNode.cpp \
    OperandNode.cpp \
    IncorrectExprExc.cpp

HEADERS += \
    TreeNode.h \
    Tree.h \
    OperatorNode.h \
    OperandNode.h \
    TreeTest.h \
    IncorrectExprExc.h
