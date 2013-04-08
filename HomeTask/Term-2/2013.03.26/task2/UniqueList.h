#pragma once

#include "ListElement.h"
#include "NothingToDelExc.h"
#include "AlreadyExistExc.h"

/** UniqueList template class interface.
    When trying to add existed item throws exception contained message.
    The same with removing. */

template <typename T>
class UniqueList
{
public:
    UniqueList() : head(NULL), tail (NULL), size(0) {}
    ~UniqueList()
    {
        if (size > 0)
            delete head;
    }

    bool isEmpty();
    void add(T item) throw (AlreadyExistExc);
    void remove(T item) throw (NothingToDelExc*);
    bool exists(T item);
    ListElement<T> *getHead()
    {
        return head;
    }
    void setHead(UniqueList<T> *tmp)
    {
        head = tmp;
    }
    ListElement<T> *getTail()
    {
        return tail;
    }
    void setTail(UniqueList<T> *tmp)
    {
        tail = tmp;
    }
    unsigned int getSize()
    {
        return size;
    }
    void setSize(unsigned int newSize)
    {
        size = newSize;
    }

private:
    ListElement<T> *head;
    ListElement<T> *tail;
    unsigned int size;
};

template <typename T>
bool UniqueList<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
void UniqueList<T>::add(T item) throw (AlreadyExistExc)
{
    if (size == 0)
    {
        ListElement<T> *temp = new ListElement<T>(item);
        head = temp;
        tail = temp;
        size++;
    }
    else
    {
        ListElement<T> *tmp = head;
        while (tmp->getNext() != NULL)
        {
            if (tmp->getItem() == item)
            {
                throw AlreadyExistExc();
            }
            tmp = tmp->getNext();
        }
        if (tail->getItem() == item)
        {
            throw AlreadyExistExc();
        }
        else
        {
            ListElement<T> *temp = new ListElement<T>(item, tail, NULL);
            tail->setNext(temp);
            tail = temp;
            size++;
        }
    }
}

template <typename T>
void UniqueList<T>::remove(T item) throw (NothingToDelExc*)
{
    if (size >= 2)
    {
        if (head->getItem() == item)
        {
            ListElement<T> *toDel = head;
            head = head->getNext();
            head->setPrev(NULL);
            toDel->setNext(NULL);
            delete toDel;
            size--;
            return;
        }
        ListElement<T> *temp = head->getNext();
        while(temp->getNext() != NULL)
        {
            if (temp->getItem() == item)
            {
                temp->getNext()->setPrev(temp->getPrev());
                temp->getPrev()->setNext(temp->getNext());
                delete temp;
                size--;
                return;
            }
            temp = temp->getNext();
        }
        if (tail->getItem() == item)
        {
            ListElement<T> *toDel = tail;
            tail = tail->getPrev();
            tail->setNext(NULL);
            size--;
            delete toDel;
            return;
        }
        throw new NothingToDelExc("No such item!");
    }

    else if (size == 1)
    {
        if (head->getItem() == item)
        {
            delete head;
            size--;
            return;
        }
        throw new NothingToDelExc("No such item!");
    }
    else
        throw new NothingToDelExc("List is empty!");
}

template <typename T>
bool UniqueList<T>::exists(T item)
{
    ListElement<T> *temp = head;
    while (temp->getNext() != NULL)
    {
        if (item == temp->getItem())
        {
            return true;
        }
        else
            temp = temp->getNext();
    }
    return temp->getItem() == item;
}
