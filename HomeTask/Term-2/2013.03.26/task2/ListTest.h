#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "UniqueList.h"

class ListTest : public QObject
{
    Q_OBJECT
private:
    UniqueList<string> *list;
private slots:
    void init()
    {
        list = new UniqueList<string>();
    }
    void addTestWithoutException()
    {
        try
        {
            list->add("one");
            list->add("two");
            list->add("three");
        }
        catch (exception)
        {
            QFAIL("");
        }
        QVERIFY(list->getHead()->getItem() == "one");
        QVERIFY(list->getHead()->getNext()->getItem() == "two");
        QVERIFY(list->getTail()->getItem() == "three");
    }
    void addTestWithException()
    {
        try
        {
            list->add("one");
            list->add("two");
            list->add("three");
            list->add("one");
        }
        catch (exception)
        {
            AlreadyExistExc exc;
            QVERIFY (string(exc.what()) == string("Item is already exist."));
        }
    }
    void isExistTest()
    {
        list->add("one");
        list->add("two");
        list->add("three");
        QVERIFY(list->exists("one") == true);
        QVERIFY(list->exists("two") == true);
        QVERIFY(list->exists("three") == true);
    }

    void removeTestWithoutException()
    {
        try
        {
            list->add("one");
            list->add("two");
            list->add("three");
            list->remove("one");
            QVERIFY(list->getHead()->getItem() == "two");
            QVERIFY(list->getHead()->getPrev() == NULL);
            QVERIFY(list->getSize() == 2);
            list->remove("two");
            QVERIFY(list->getHead()->getItem() == "three");
            QVERIFY(list->getHead()->getPrev() == NULL);
            QVERIFY(list->getHead()->getNext() == NULL);
            QVERIFY(list->getHead() == list->getTail());
            QVERIFY(list->getSize() == 1);
            list->remove("three");
            QVERIFY(list->getSize() == 0);
        }
        catch (exception)
        {
            QFAIL("");
        }
    }
    void removeTestWithException()
    {
        try
        {
            list->add("one");
            list->add("two");
            list->add("three");
            list->remove("one");
            list->remove("four");
        }
        catch (exception *exc)
        {
            QVERIFY(string(exc->what()) == string("Nothing to delete: No such item!"));
            delete exc;
        }
    }
    void removeFromEmptyListTest()
    {
        try
        {
            list->remove("one");
        }
        catch (exception *exc)
        {
            QVERIFY(string(exc->what()) == string("Nothing to delete: List is empty!"));
            delete exc;
        }
    }

    void cleanup()
    {
        delete list;
    }
};
