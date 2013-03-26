#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "QuickSorter.h"

class SorterTest : public QObject
{
    Q_OBJECT
private:
    int **array;
    static const int row = 5;
    static const int column = 4;
    int **generateArray(int row, int column)
    {
        srand(time(0));
        int **array = new int *[row];
        for (int i = 0; i < row; i++)
        {
            array[i] = new int[column];
            for (int j = 0; j < column; j++)
            {
                array[i][j] = rand() % 50 + 10;
            }
        }
        return array;
    }

    void destroyArray(int **array, int row)
    {
        for (int i = 0; i < row; i++)
        {
            delete []array[i];
        }
        delete []array;
    }

private slots:
    void init()
    {
        array = generateArray(row, column);
    }
    void SortTest()
    {
        QuickSorter arraySorter(array, row, column);
        arraySorter.sort();
        for (int i = 0; i < row - 1; i++)
        {
            if (arraySorter.array[i][0] > arraySorter.array[i + 1][0])
                QFAIL("");
        }
    }
    void cleanup()
    {
        destroyArray(array, row);
    }
};
