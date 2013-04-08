#pragma once

#include <stdlib.h>
#include <iostream>
using namespace std;

/** ListElement template class interface. */

template <typename T>
class ListElement
{
public:
    ListElement(T itm) : item(itm), prev(NULL), next(NULL) {}
    ListElement(T itm, ListElement<T> *prevElem, ListElement<T> *nextElem) : item(itm), prev(prevElem),
        next(nextElem)  {}
    ~ListElement()
    {
        if (next != NULL)
            delete next;
    }
    ListElement<T> *getNext()
    {
        return next;
    }
    void setNext(ListElement<T> *newNext)
    {
        next = newNext;
    }
    ListElement<T> *getPrev()
    {
        return prev;
    }
    void setPrev(ListElement<T> *newPrev)
    {
        prev = newPrev;
    }
    string getItem()
    {
        return item;
    }
    void setItem(string newItem)
    {
        item = newItem;
    }
private:
    T item;
    ListElement<T> *prev;
    ListElement<T> *next;
};
