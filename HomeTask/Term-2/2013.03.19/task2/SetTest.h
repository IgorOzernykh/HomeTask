#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "Set.h"
#include <iostream>

class SetTest : public QObject
{
    Q_OBJECT
private:
    Set<int> *mySet;
private slots:
    void init()
    {
        mySet = new Set<int>();
    }

    void AddTest1()
    {

        try
        {
            mySet->add(123);
            QVERIFY(mySet->exists(123));
        }
        catch (AlreadyExistExc)
        {
            QFAIL("");
        }
    }
    void AddTest2()
    {
        try
        {
            for (int i = 0; i < 50; i++)
            {
                mySet->add(i);
            }
        }
        catch (AlreadyExistExc)
        {
            QFAIL("");
        }
        for (int i = 0; i < 50; i++)
        {
            QVERIFY(mySet->exists(i));
        }
    }
    void removeTest()
    {
        try
        {
            mySet->add(123);
        }
        catch (AlreadyExistExc)
        {
            QFAIL("");
        }
        try
        {
            mySet->remove(123);
        }
        catch (std::exception *exc)
        {
            QFAIL("");
            delete exc;
        }
    }
    void mergeTest()
    {
        Set<int> *anotherSet =  new Set<int>();
        try
        {
            for (int i = 0; i < 50; i++)
            {
                mySet->add(i);
                anotherSet->add(i + 50);
            }
        }
        catch (AlreadyExistExc)
        {
            QFAIL("");
        }
        Set<int> *result = mySet->merge(anotherSet);
        for (int i = 0; i < 100; i++)
        {
            QVERIFY(result->exists(i));
        }
        delete anotherSet;
    }
    void intersectTest()
    {
        Set<int> *anotherSet =  new Set<int>();
        try
        {
            for (int i = 0; i < 50; i++)
            {
                mySet->add(i);
                anotherSet->add(i + 30);
            }
        }
        catch (AlreadyExistExc)
        {
            QFAIL("");
        }
        Set<int> *result = mySet->intersect(anotherSet);
        for (int i = 0; i < 30; i++)
        {
            QVERIFY(!result->exists(i));
        }
        for (int i = 30; i < 50; i++)
        {
            QVERIFY(result->exists(i));
        }
        for (int i = 50; i < 80; i++)
        {
            QVERIFY(!result->exists(i));
        }
        delete anotherSet;
    }

    void cleanup()
    {
        delete mySet;
    }
};
