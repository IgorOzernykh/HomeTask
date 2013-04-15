#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "AVLTree.h"

class AVLTreeTest : public QObject
{
    Q_OBJECT
private:
    AVLTree<int> *tree;
private slots:
    void init()
    {
        tree = new AVLTree<int>();
    }
    void addTest()
    {
        for (int i = 15; i > 0; i--)
        {
            tree->add(i);
        }
        QVERIFY(tree->TreeHeight() == 4);
        for (int i = 1; i <= 15; i++)
        {
            QVERIFY(tree->isExist(i));
        }
    }
    void removeOneElemTest()
    {
        for (int i = 0; i < 10; i++)
        {
            tree->add(8);
        }
        QVERIFY(tree->TreeHeight() == 1);
        QVERIFY(tree->getRoot()->getElemCounter() == 10);
        try
        {
            tree->removeElement(8);
        }
        catch (std::exception)
        {
            QFAIL("");
        }
        QVERIFY(tree->getRoot()->getElemCounter() == 9);
    }
    void removeNodeTest()
    {
        for (int i = 0; i < 10; i++)
        {
            tree->add(8);
        }
        QVERIFY(tree->TreeHeight() == 1);
        QVERIFY(tree->NodeCount() == 1);
        QVERIFY(tree->getRoot()->getElemCounter() == 10);
        try
        {
            tree->removeNode(8);
        }
        catch (std::exception)
        {
            QFAIL("");
        }

        QVERIFY(tree->NodeCount() == 0);
        QVERIFY(tree->TreeHeight() == 0);
    }
    void RemoveNonExistElem()
    {
        tree->add(123);
        try
        {
            tree->removeElement(12);
        }
        catch(std::exception *exc)
        {
            QVERIFY(std::string(exc->what()) == std::string("Nothing to delete: No such value!"));
            delete exc;
        }
    }

    void cleanup()
    {
        delete tree;
    }
};
