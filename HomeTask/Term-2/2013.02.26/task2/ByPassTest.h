#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "ByPass.h"

class ByPassTest : public QObject
{
    Q_OBJECT
private:
    int **array3x3;
    int **array5x5;
    static const int size3x3 = 3;
    static const int size5x5 = 5;
    ByPass *SpiralInLineArray;
private slots:
    void init()
    {

        int elemValue = 1;
        array3x3 = new int*[size3x3];
        for (int i = 0; i < size3x3; i++)
        {
            array3x3[i] = new int[size3x3];
            for (int j = 0; j < size3x3; j++)
            {
                array3x3[i][j] = elemValue++;
            }
        }

        elemValue = 1;
        array5x5 = new int*[size5x5];
        for (int i = 0; i < size5x5; i++)
        {
            array5x5[i] = new int[size5x5];
            for (int j = 0; j < size5x5; j++)
            {
                array5x5[i][j] = elemValue++;
            }
        }
        SpiralInLineArray = new ByPass;
    }
    void ByPassTest3x3()
    {
        bool equal = true;
        int patternArray[] = {5, 6, 9, 8, 7, 4, 1, 2, 3};
        int *byPassArray = SpiralInLineArray->SpiralByPass(array3x3, size3x3);
        for (int i = 0; i < size3x3 * size3x3; i++)
        {
            if (byPassArray[i] != patternArray[i])
                QFAIL("");
        }
        QVERIFY(equal == true);
    }
    void ByPassTest5x5()
    {
        bool equal = true;
        int patternArray[] = {13, 14, 19, 18, 17, 12, 7, 8, 9, 10, 15, 20, 25, 24,
                                        23, 22, 21, 16, 11, 6, 1, 2, 3, 4, 5};
        int *byPassArray = SpiralInLineArray->SpiralByPass(array5x5, size5x5);
        for (int i = 0; i < size5x5 * size5x5; i++)
        {
            if (byPassArray[i] != patternArray[i])
                QFAIL("");
        }
        QVERIFY(equal == true);
    }
    void cleanup()
    {
        delete SpiralInLineArray;
        for (int i = 0; i < size3x3; i++)
        {
            delete []array3x3[i];
        }
        delete array3x3;
        for (int i = 0; i < size5x5; i++)
        {
            delete []array5x5[i];
        }
        delete array5x5;
    }
};
