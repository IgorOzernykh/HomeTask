#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "AVLTree.h"

class AVLTreeIteratorTest : public QObject
{
    Q_OBJECT
private:
    AVLTree<int> *tree;
private slots:
    void init()
    {
        tree = new AVLTree<int>();
    }

    void IteratorTest()
    {
        for (int i = 7; i > 0; i--)
        {
            tree->add(i);
        }
        AVLTree<int>::AVLTreeIterator iter(tree);
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
            tree->add(i);
        }
        AVLTree<int>::AVLTreeIterator iter(tree);
        try
        {
            iter.remove();
            QVERIFY(!tree->isExist(4));
            QVERIFY(iter.next() == 2);
            QVERIFY(iter.next() == 1);
            QVERIFY(iter.next() == 3);
            iter.remove();
            QVERIFY(!tree->isExist(6));
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
            tree->add(i);
        }
        AVLTree<int>::AVLTreeIterator iter(tree);
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
            tree->add(i);
        }
        AVLTree<int>::AVLTreeIterator iter(tree);
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
            tree->add(i);
        }
        AVLTree<int>::AVLTreeIterator iter(tree);
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
        delete tree;
    }
};
