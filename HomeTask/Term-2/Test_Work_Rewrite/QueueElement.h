#pragma once
#include <stdlib.h>

/** QueueElement template class interface. */

template <typename T>
class QueueElement
{
public:
    QueueElement(T itm, unsigned int prt) : next(NULL), prev(NULL), item(itm), priority(prt) {}
    ~QueueElement()
    {
        if (next != NULL)
            delete next;
    }
    unsigned int getPriority()
    {
        return priority;
    }
    void setPriority(unsigned int newPriority)
    {
        priority = newPriority;
    }
    T getItem()
    {
        return item;
    }
    void setItem(T newItem)
    {
        item = newItem;
    }
    QueueElement<T> *getNext()
    {
        return next;
    }
    void setNext(QueueElement<T> *newNext)
    {
        next = newNext;
    }
    QueueElement<T> *getPrev()
    {
        return prev;
    }
    void setPrev(QueueElement<T> *newPrev)
    {
        prev = newPrev;
    }
private:
    QueueElement<T> *next;
    QueueElement<T> *prev;
    T item;
    unsigned int priority;
};
