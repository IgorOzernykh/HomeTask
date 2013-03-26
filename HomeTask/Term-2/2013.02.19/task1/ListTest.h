#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "PointerList.h"
#include "ArrayList.h"

class ListTest : public QObject
{
    Q_OBJECT
private:
    List *alist;
    List *plist;
private slots:
    void init()
    {
        alist = new ArrayList;
        plist = new PointerList;
    }
    void addTest1()
    {
        try
        {
        alist->add(1);
        alist->add(2);
        alist->add(3);
        plist->add(1);
        plist->add(2);
        plist->add(3);
        QVERIFY((*alist)[0] == 1);
        QVERIFY((*plist)[0] == 1);
        QVERIFY((*alist)[1] == 2);
        QVERIFY((*plist)[1] == 2);
        QVERIFY((*alist)[2] == 3);
        QVERIFY((*plist)[2] == 3);
        QVERIFY((*alist)[3] == 3);
        QVERIFY((*plist)[3] == 3);
        }
        catch (string alreadyExistExc)
        {
            QFAIL("");
        }
    }
    void addTest2()
    {
        try
        {
            alist->add(1);
            alist->add(2);
            alist->add(3);
            alist->add(2);
        }
        catch (string alreadyExistExc)
        {
            QVERIFY(alreadyExistExc == string("Value is already exist in ArrayList - ", 2));
        }
    }
    void addTest3()
    {
        try
        {
            plist->add(1);
            plist->add(2);
            plist->add(3);
            plist->add(2);
        }
        catch (string alreadyExistExc)
        {
            QVERIFY(alreadyExistExc == string("Value is already exist in PointerList - ", 2));
        }
    }

    void removeTest1()
    {
        try
        {
            alist->add(1);
            alist->add(2);
            alist->add(3);
            plist->add(1);
            plist->add(2);
            plist->add(3);
            alist->remove(2);
            plist->remove(2);
            QVERIFY((*alist)[1] == 3);
            QVERIFY((*plist)[1] == 3);
        }
        catch (string NoSuchValueExc)
        {
            QFAIL("");
        }

    }
    void removeTest2()
    {
        try
        {
            alist->add(1);
            alist->add(2);
            alist->add(3);
            alist->remove(5);
        }
        catch (string NoSuchValueExc)
        {
            QVERIFY(NoSuchValueExc == string("No value = ", 5));
        }
    }
    void removeTest3()
    {
        try
        {
            plist->add(1);
            plist->add(2);
            plist->add(3);
            plist->remove(6);
        }
        catch (string NoSuchValueExc)
        {
            QVERIFY(NoSuchValueExc == string("No value = ", 6));
        }
    }

    void showTest1()
    {
        try
        {
            alist->show();
        }
        catch (string listIsEmptyExc)
        {
            QVERIFY(listIsEmptyExc == string("Nothing to show! ArrayList is empty!"));
        }
    }
    void showTest2()
    {
        try
        {
            plist->show();
        }
        catch (string listIsEmptyExc)
        {
            QVERIFY(listIsEmptyExc == string("Nothing to show! PointerList is empty!"));
        }
    }
    void cleanup()
    {
        delete alist;
        delete plist;
    }
};
