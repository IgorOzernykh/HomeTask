#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "BinarySearchTree.h"

class TreeTest : public QObject
{
    Q_OBJECT
private:
    BinarySearchTree<int> *tree;
private slots:
    void init()
    {
        tree = new BinarySearchTree<int>();
    }
    void addWhenAlreadyExistTest()
    {
        try
        {
            tree->add(5);
            tree->add(5);
            QFAIL("");
        }
        catch (AlreadyExistExc)
        {
            AlreadyExistExc exception;
            QVERIFY(std::string(exception.what()) == std::string("Item is already exist."));
        }
    }

    void addTest()
    {
        try
        {
            tree->add(55);
            tree->add(13);
            tree->add(87);
            tree->add(58);
            tree->add(24);
            QVERIFY(tree->getRoot()->getItem() == 55);
            QVERIFY(tree->getRoot()->getLeftChild()->getItem() == 13);
            QVERIFY(tree->getRoot()->getRightChild()->getItem() == 87);
            QVERIFY(tree->getRoot()->getLeftChild()->getRightChild()->getItem() == 24);
            QVERIFY(tree->getRoot()->getRightChild()->getLeftChild()->getItem() == 58);
        }
        catch (AlreadyExistExc)
        {
            QFAIL("");
        }
    }
    void removeFromEmptyTreeTest()
    {
        try
        {
            tree->remove(4);
            QFAIL("");
        }
        catch(std::exception *exc)
        {
            QVERIFY(std::string(exc->what()) == std::string("Nothing to delete: Tree is empty!"));
            delete exc;
        }
    }
    void searchTest()
    {
        tree->add(53);
        tree->add(81);
        tree->add(47);
        tree->add(64);
        tree->add(71);
        QVERIFY(tree->isExist(64));
    }
    void removeNonexistentValueTest()
    {
        try
        {
            tree->add(53);
            tree->add(81);
            tree->add(47);
            tree->add(64);
            tree->add(71);
            tree->remove(54);
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
