#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "BubbleSorter.h"
#include "HeapSorter.h"
#include "QuickSorter.h"

class SorterTest : public QObject
{
    Q_OBJECT
private:
    Sorter *bsorter;
    Sorter *hsorter;
    Sorter *qsorter;
    int *arrayToSort;
    static const int size = 10;
    bool isSorted(int *array, int size)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
                return false;
        }
        return true;
    }

private slots:
    void init()
    {
        arrayToSort = new int[size];
        for (int i = 0; i < size; i++)
        {
            arrayToSort[i] = rand() % 50 - 25;
        }
        hsorter = new HeapSorter(arrayToSort, size);
        bsorter = new BubbleSorter(arrayToSort, size);
        qsorter = new QuickSorter(arrayToSort, size);
    }
    void HsorterTest()
    {
        hsorter->sort();
        QVERIFY (isSorted(hsorter->array, size) == true);
    }
    void BsorterTest()
    {
        bsorter->sort();
        QVERIFY (isSorted(bsorter->array, size) == true);
    }
    void QsorterTest()
    {
        qsorter->sort();
        QVERIFY (isSorted(qsorter->array, size) == true);
    }
    void cleanup()
    {
        delete []arrayToSort;
        delete hsorter;
        delete bsorter;
        delete qsorter;
    }
};
