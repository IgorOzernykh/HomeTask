#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "Bag.h"

class BagIteratorTest : public QObject
{
    Q_OBJECT
private:
    Bag<int> *bag;
private slots:
    void init()
    {
        bag = new Bag<int>();
    }

    void IteratorTest()
    {
        for (int i = 7; i > 0; i--)
        {
            bag->add(i);
        }
        Bag<int>::Iterator iter(bag);
        try
        {
            QVERIFY(iter.next() == 4);
            QVERIFY(iter.next() == 2);
            QVERIFY(iter.next() == 1);
            QVERIFY(iter.next() == 3);
            QVERIFY(iter.next() == 6);
            QVERIFY(iter.next() == 5);
            QVERIFY(iter.next() == 7);
        }
        catch (std::exception)
        {
            QFAIL("");
        }
    }
    void removeTest()
    {
        for (int i = 7; i > 0; i--)
        {
            bag->add(i);
        }
        Bag<int>::Iterator iter(bag);
        try
        {
            iter.remove();
            QVERIFY(!bag->search(4));
            QVERIFY(iter.next() == 2);
            QVERIFY(iter.next() == 1);
            QVERIFY(iter.next() == 3);
            iter.remove();
            QVERIFY(!bag->search(6));
            QVERIFY(iter.next() == 5);
            QVERIFY(iter.next() == 7);

        }
        catch (std::exception)
        {
            QFAIL("");
        }
    }
    void SequenceTest()
    {
        for (int i = 7; i > 0; i--)
        {
            bag->add(i);
        }
        Bag<int>::Iterator iter(bag);
        for (int i = 0; i < 5; i++)
        {
            iter.add(6);
        }
        try
        {
            QVERIFY(iter.next() == 4);
            QVERIFY(iter.next() == 2);
            QVERIFY(iter.next() == 1);
            QVERIFY(iter.next() == 3);
            QVERIFY(iter.next() == 6);
            QVERIFY(iter.next() == 6);
            QVERIFY(iter.next() == 6);
            QVERIFY(iter.next() == 6);
            QVERIFY(iter.next() == 6);
            QVERIFY(iter.next() == 6);
            QVERIFY(iter.next() == 5);
            QVERIFY(iter.next() == 7);
        }
        catch (std::exception)
        {
            QFAIL("");
        }
    }
    void hasNextTest()
    {
        for (int i = 7; i > 0; i--)
        {
            bag->add(i);
        }
        Bag<int>::Iterator iter(bag);
        try
        {
            for (int i = 0; i < 6; i++)
            {
                QVERIFY(iter.hasNext());
                iter.next();
            }
            QVERIFY(!iter.hasNext());
        }
        catch (std::exception)
        {
            QFAIL("");
        }
    }
    void endOfSetTest()
    {
        for (int i = 7; i > 0; i--)
        {
            bag->add(i);
        }
        Bag<int>::Iterator iter(bag);
        try
        {
            for (int i = 0; i < 8; i++)
            {
                iter.next();
            }
            QFAIL("");
        }
        catch (std::exception exc)
        {
            EndOfSetExc exc;
            QVERIFY(std::string(exc.what()) == std::string("No more elements!"));
        }
    }

    void cleanup()
    {
        delete bag;
    }
};
