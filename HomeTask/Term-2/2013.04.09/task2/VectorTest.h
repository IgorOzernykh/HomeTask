#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "Vector.h"

class VectorTest :public QObject
{
    Q_OBJECT
private slots:
    void EqualtyTest()
    {
        Vector<3> v1;
        Vector<3> v2;
        for (int i = 0; i < 3; i++)
        {
            v1[i] = i;
            v2[i] = i;
        }
        QVERIFY(v1 == v2);
    }
    void InequalityTest()
    {
        Vector<3> v1;
        Vector<3> v2;
        for (int i = 0; i < 3; i++)
        {
            v1[i] = i;
            v2[i] = i;
        }
        v2[2] = 4;
        QVERIFY(v1 != v2);
    }
    void AdditionTest()
    {
        Vector<3> v1;
        Vector<3> v2;
        for (int i = 0; i < 3; i++)
        {
            v1[i] = i + 1;
            v2[i] = i + 4;
        }
        Vector<3> result = v1 + v2;
        QVERIFY(result[0] == 5 && result[1] == 7 && result[2] == 9);
    }
    void SubTractionTest()
    {
        Vector<3> v1;
        Vector<3> v2;
        for (int i = 0; i < 3; i++)
        {
            v1[i] = i + 1;
            v2[i] = i + 4;
        }
        Vector<3> result = v2 - v1;
        QVERIFY(result[0] == 3 && result[1] == 3 && result[2] == 3);
    }
    void AssignmentTest()
    {
        Vector<3> v1;
        Vector<3> v2;
        for (int i = 0; i < 3; i++)
        {
            v1[i] = i + 1;
        }
        v2 = v1;
        QVERIFY(v1 == v2);
    }
    void ScalarMultiplicationTest()
    {
        Vector<3> v1;
        Vector<3> v2;
        for (int i = 0; i < 3; i++)
        {
            v1[i] = i + 1;
            v2[i] = i + 4;
        }
        int result = v1 * v2;
        QVERIFY(result == 32);
    }
    void isZeroTest()
    {
        Vector<3> v1;
        QVERIFY(v1.isZero());
        v1[1] = 1;
        QVERIFY(!v1.isZero());
    }
    void CopyConstructorTest()
    {
        Vector<3> v1;
        for (int i = 0; i < 3; i++)
        {
            v1[i] = i + 1;
        }
        Vector<3> copy(v1);
        QVERIFY (v1 == copy);
    }

};
