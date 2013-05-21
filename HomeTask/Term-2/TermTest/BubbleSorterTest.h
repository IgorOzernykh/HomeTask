#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "BubbleSorter.h"

class BubbleSorterTest : public QObject
{
    Q_OBJECT
private:
    static const int arraySize = 10;
private slots:
    void sortIntTest()
    {
        int *array = new int[arraySize];
        array[0] = 10;
        array[1] = 7;
        array[2] = 14;
        array[3] = 4;
        array[4] = 12;
        array[5] = 47;
        array[6] = 52;
        array[7] = 1;
        array[8] = 19;
        array[9] = 28;

        BubbleSorter<int>::bSort(array, arraySize);

        QVERIFY(array[0] == 1);
        QVERIFY(array[1] == 4);
        QVERIFY(array[2] == 7);
        QVERIFY(array[3] == 10);
        QVERIFY(array[4] == 12);
        QVERIFY(array[5] == 14);
        QVERIFY(array[6] == 19);
        QVERIFY(array[7] == 28);
        QVERIFY(array[8] == 47);
        QVERIFY(array[9] == 52);
    }

    void sortCharTest()
    {
        char *array = new char[arraySize];
        array[0] = 'z';
        array[1] = 'B';
        array[2] = 'E';
        array[3] = '2';
        array[4] = 's';
        array[5] = '0';
        array[6] = 'P';
        array[7] = 'q';
        array[8] = 'Y';
        array[9] = 'd';

        BubbleSorter<char>::bSort(array, arraySize);

        QVERIFY(array[0] == '0');
        QVERIFY(array[1] == '2');
        QVERIFY(array[2] == 'B');
        QVERIFY(array[3] == 'E');
        QVERIFY(array[4] == 'P');
        QVERIFY(array[5] == 'Y');
        QVERIFY(array[6] == 'd');
        QVERIFY(array[7] == 'q');
        QVERIFY(array[8] == 's');
        QVERIFY(array[9] == 'z');
    }

    void sortStringTest()
    {
        std::string *array = new std::string[arraySize];
        array[0] = "qwet";
        array[1] = "qwer";
        array[2] = "134er";
        array[3] = "akfj";
        array[4] = "094sdr";
        array[5] = "vcxzvx";
        array[6] = "PSDsds";
        array[7] = "FVdra#4";
        array[8] = "DKF91{{sd";
        array[9] = "ydf34#f!!!";

        BubbleSorter<std::string>::bSort(array, arraySize);

        QVERIFY(array[0] == "094sdr");
        QVERIFY(array[1] == "134er");
        QVERIFY(array[2] == "DKF91{{sd");
        QVERIFY(array[3] == "FVdra#4");
        QVERIFY(array[4] == "PSDsds");
        QVERIFY(array[5] == "akfj");
        QVERIFY(array[6] == "qwer");
        QVERIFY(array[7] == "qwet");
        QVERIFY(array[8] == "vcxzvx");
        QVERIFY(array[9] == "ydf34#f!!!");
    }

    void sortCharArrayTest()
    {
        char **array = new char*[arraySize];
        const int stringSize = 10;
        for (int i = 0; i < arraySize; i++)
        {
            array[i] = new char[stringSize];
        }

        array[0] = "qwet";
        array[1] = "qwer";
        array[2] = "134er";
        array[3] = "akfj";
        array[4] = "094sdr";
        array[5] = "vcxzvx";
        array[6] = "PSDsds";
        array[7] = "FVdra#4";
        array[8] = "DKF91{{sd";
        array[9] = "ydf34#f!!";

        BubbleSorter<char*>::bSort(array, arraySize);

        QVERIFY(Comparer<char*>::compare(array[0], "094sdr") == 0);
        QVERIFY(Comparer<char*>::compare(array[1], "134er") == 0);
        QVERIFY(Comparer<char*>::compare(array[2], "DKF91{{sd") == 0);
        QVERIFY(Comparer<char*>::compare(array[3], "FVdra#4") == 0);
        QVERIFY(Comparer<char*>::compare(array[4], "PSDsds") == 0);
        QVERIFY(Comparer<char*>::compare(array[5], "akfj") == 0);
        QVERIFY(Comparer<char*>::compare(array[6], "qwer") == 0);
        QVERIFY(Comparer<char*>::compare(array[7], "qwet") == 0);
        QVERIFY(Comparer<char*>::compare(array[8], "vcxzvx") == 0);
        QVERIFY(Comparer<char*>::compare(array[9], "ydf34#f!!") == 0);
    }
};
