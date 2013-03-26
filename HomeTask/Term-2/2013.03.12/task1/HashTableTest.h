#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "HashTable.h"
#include "HashFunction.h"

class HashTableTest : public QObject
{
    Q_OBJECT
private:
    HashTable *table;
    HashFunction *shash;
    HashFunction *xhash;
    static const unsigned int size = 100;
private slots:
    void init()
    {
        shash = new SumHash;
        xhash = new XorHash;
        table = new HashTable(size, shash);
    }
    void addTest()
    {
        table->add("one", 1);
        unsigned int key1 = table->hash->hash("one") % table->HTsize;
        QVERIFY(table->table[key1]->head->str == "one");
        table->add("two", 1);
        unsigned int key2 = table->hash->hash("two") % table->HTsize;
        QVERIFY(table->table[key2]->head->str == "two");
        table->add("three", 1);
        unsigned int key3 = table->hash->hash("three") % table->HTsize;
        QVERIFY(table->table[key3]->head->str == "three");
    }
    void isExistTest()
    {
        table->add("one", 1);
        table->add("two", 1);
        table->add("three", 1);
        QVERIFY(table->isExist("one") == true);
        QVERIFY(table->isExist("two") == true);
        QVERIFY(table->isExist("three") == true);
    }
    void rebuildTableTest()
    {
        table->add("one", 1);
        table->add("two", 1);
        table->add("three", 1);
        unsigned int oldkey1 = table->hash->hash("one") % table->HTsize;
        unsigned int oldkey2 = table->hash->hash("two") % table->HTsize;
        unsigned int oldkey3 = table->hash->hash("three") % table->HTsize;
        xhash = new XorHash;
        table->rebuildTable(100, xhash);
        unsigned int key1 = table->hash->hash("one") % table->HTsize;
        QVERIFY(table->table[key1]->head->str == "one");
        unsigned int key2 = table->hash->hash("two") % table->HTsize;
        QVERIFY(table->table[key2]->head->str == "two");
        unsigned int key3 = table->hash->hash("three") % table->HTsize;
        QVERIFY(table->table[key3]->head->str == "three");
        QVERIFY((key1 != oldkey1 || key2 != oldkey2 || key3 != oldkey3) == true);
    }
    void removeTest()
    {
        table->add("one", 1);
        table->add("two", 1);
        table->add("three", 1);
        unsigned int key1 = table->hash->hash("one") % table->HTsize;
        unsigned int key2 = table->hash->hash("two") % table->HTsize;
        unsigned int key3 = table->hash->hash("three") % table->HTsize;
        try
        {
            table->remove("one");
            QVERIFY(table->table[key1]->isEmpty() == true);
            table->remove("two");
            QVERIFY(table->table[key2]->isEmpty() == true);
            table->remove("three");
            QVERIFY(table->table[key3]->isEmpty() == true);
            table->remove("1");
        }
        catch (string exc)
        {
            QVERIFY(exc == "No such word");
        }
    }
    void cleanup()
    {
        delete table;
        delete shash;
        delete xhash;
    }
};