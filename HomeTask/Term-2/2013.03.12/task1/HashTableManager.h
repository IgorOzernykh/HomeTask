#pragma once
#include "HashTable.h"

class HashTableManager
{
public:
    HashTableManager();
    ~HashTableManager();
    void showStatistics();
    void changeHash();
    void menu();
    void dialog();
private:
    HashTable *table;
    unsigned int HTsize;
    HashFunction *shash;
    HashFunction *xhash;
    HashFunction *currenthash;
};

