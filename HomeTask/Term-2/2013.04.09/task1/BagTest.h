#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "Bag.h"

class BagTest : public QObject
{
    Q_OBJECT
private:
    Bag<int> *bag;
private slots:
    void init()
    {
        bag = new Bag<int>();
    }
    void addTest()
    {
        for (int i = 0; i < 10; i++)
        {
            bag->add(i);
        }
        for (int i = 0; i < 10; i++)
        {
            QVERIFY(bag->search(i));
        }
    }
    void removeOneElemTest()
    {
        for (int i = 0; i < 10; i++)
        {
             bag->add(123);
        }
        QVERIFY(bag->search(123));
        bag->removeOneElement(123);
        QVERIFY(bag->search(123));
    }
    void removeAllElemsTest()
    {
        for (int i = 0; i < 10; i++)
        {
             bag->add(123);
        }
        QVERIFY(bag->search(123));
        bag->removeAllElements(123);
        QVERIFY(!bag->search(123));
    }
    void removeNonExistValue()
    {
        bag->add(123);
        try
        {
            bag->removeOneElement(2);
        }
        catch(std::exception *exc)
        {
            QVERIFY(std::string(exc->what()) == std::string("Nothing to delete: No such value!"));
            delete exc;
        }
    }
    void cleanup()
    {
        delete bag;
    }
};
