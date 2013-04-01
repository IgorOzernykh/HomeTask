#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "List.h"

class ListTest : public QObject
{
    Q_OBJECT
private:
    List *list;
private slots:
    void init()
    {
        list = new List;
    }
    void addTest()
    {
        list->add("one", 1);
        list->add("two", 2);
        list->add("three", 3);
        QVERIFY(list->getHead()->getStr() == "one");
        QVERIFY(list->getHead()->getNext()->getStr() == "two");
        QVERIFY(list->getTail()->getStr() == "three");
        QVERIFY(list->getHead()->getElemCounter() == 1);
        QVERIFY(list->getHead()->getNext()->getElemCounter() == 2);
        QVERIFY(list->getTail()->getElemCounter() == 3);
    }
    void isExistTest()
    {
        list->add("one", 1);
        list->add("two", 2);
        list->add("three", 3);
        QVERIFY(list->exists("one") == true);
        QVERIFY(list->exists("two") == true);
        QVERIFY(list->exists("three") == true);
    }

    void removeTest()
    {
        list->add("one", 1);
        list->add("two", 2);
        list->add("three", 3);
        list->remove("one");
        QVERIFY(list->getHead()->getStr() == "two");
        QVERIFY(list->getHead()->getPrev() == NULL);
        QVERIFY(list->getSize() == 2);
        list->remove("two");
        QVERIFY(list->getHead()->getStr() == "three");
        QVERIFY(list->getHead()->getPrev() == NULL);
        QVERIFY(list->getHead()->getNext() == NULL);
        QVERIFY(list->getHead() == list->getTail());
        QVERIFY(list->getSize() == 1);
        list->remove("three");
        QVERIFY(list->getSize() == 0);
    }
    void cleanup()
    {
        delete list;
    }
};
