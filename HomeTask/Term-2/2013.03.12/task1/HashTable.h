#pragma once

#include "List.h"
#include "HashFunction.h"

/** HashTable class interface.
    It contains string words */

class HashTable
{
public:
    HashTable(unsigned int size, HashFunction *hashFunct);
    ~HashTable();
    void createTable();
    void add (string str, unsigned int quantity);
    void remove (string str) throw (string);
    bool isExist (string str);
    void rebuildTable(unsigned int newSize, HashFunction *hashFunct);
    /** Function checks loadFactor and restruct table if it's necessary */
    void checkOverFlow();
    HashFunction *getHash()
    {
        return hash;
    }
    unsigned int getHTsize()
    {
        return HTsize;
    }
    unsigned int getCollisions()
    {
        return Collisions;
    }
    unsigned int getMaxCollLength()
    {
        return MaxCollLength;
    }
    unsigned int getElemQuantity()
    {
        return ElemQuantity;
    }
    double getLoadFactor()
    {
        return LoadFactor;
    }
    List *getTableElement(unsigned int index)
    {
        return table[index];
    }

private:
    unsigned int HTsize;
    unsigned int Collisions;
    unsigned int MaxCollLength;
    unsigned int ElemQuantity;
    double LoadFactor;
    HashFunction *hash;
    List **table;
};

