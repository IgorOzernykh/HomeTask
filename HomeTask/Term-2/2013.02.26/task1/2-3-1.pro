CONFIG   += console qtestlib

TEMPLATE = app


SOURCES += main.cpp \
    Sorter.cpp \
    BubbleSorter.cpp \
    QuickSorter.cpp \
    HeapSorter.cpp

HEADERS += \
    Sorter.h \
    QuickSorter.h \
    BubbleSorter.h \
    HeapSorter.h \
    SorterTest.h
