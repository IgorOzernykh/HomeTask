#include "HashTable.h"

HashTable::HashTable(unsigned int size, HashFunction *hashFunct) :
    HTsize(size),

    Collisions(0),
    MaxCollLength(0),
    ElemQuantity(0),
    LoadFactor(0),
    hash(hashFunct)
{
    createTable();
}

void HashTable::createTable()
{
    table = new List *[HTsize];
    for (unsigned int i = 0; i < HTsize; i++)
    {
        table[i] = NULL;
    }
}

void HashTable::add(string str, unsigned int quantity)
{
    unsigned long long int index = hash->hash(str) % HTsize;
    if (table[index] == NULL)
    {
        table[index] = new List();
        table[index]->add(str, quantity);
        ElemQuantity++;
        LoadFactor += 1.0 / double(HTsize);
        return;
    }
    unsigned int listSize = table[index]->getSize();
    table[index]->add(str, quantity);
    if (table[index]->getSize() > listSize)
    {
        Collisions++;
        ElemQuantity++;
        if (MaxCollLength < table[index]->getSize() - 1)
            MaxCollLength = table[index]->getSize() - 1;
    }
}


void HashTable::remove(string str) throw (string)
{
    unsigned long long int index = hash->hash(str) % HTsize;
    if (table[index] != NULL)
    {
        try
        {
            table[index]->remove(str);
        }
        catch (string exc)
        {
            cout << exc << endl;

        }
    }
    else
        throw string("No such word");
}

bool HashTable::isExist(string str)
{
    unsigned long long int index = hash->hash(str) % HTsize;
    if (table[index] != NULL && !table[index]->isEmpty())
    {
        ListElement *temp = table[index]->getHead();
        while(temp->getNext() != NULL)
        {
            if (temp->getStr() == str)
            {
                return true;
            }
            else
            {
                temp = temp->getNext();
            }
        }
        return temp->getStr() == str;
    }
    else
        return false;
}

void HashTable::rebuildTable(unsigned int newSize, HashFunction *hashFunct)
{
    List **oldTable = table;
    unsigned int oldSize = HTsize;
    HTsize = newSize;
    createTable();
    Collisions = 0;
    MaxCollLength = 0;
    LoadFactor = 0;
    ElemQuantity = 0;
    hash = hashFunct;
    for (unsigned int i = 0; i < oldSize; i++)
    {
        if (oldTable[i] != NULL && !oldTable[i]->isEmpty())
        {
            ListElement *temp = oldTable[i]->getHead();
            while (temp->getNext() != NULL)
            {
                add(temp->getStr(), temp->getElemCounter());
                temp = temp->getNext();
            }
            add(temp->getStr(), temp->getElemCounter());
        }
    }
    delete oldTable;
}

void HashTable::checkOverFlow()
{
    if (LoadFactor > 0.6)
        rebuildTable(2 * HTsize, hash);
}

HashTable::~HashTable()
{
    for (unsigned int i = 0; i < HTsize; i++)
    {
        if (table[i] != NULL)
            delete table[i];
    }
    delete []table;
    delete hash;
}
