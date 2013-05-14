#pragma once
#include "QueueElement.h"
#include "QueueIsEmptyExc.h"

/** PriorityQueue template class interface.
    When trying to dequeue element from empty queue throws exception */

template <typename T>
class PriorityQueue
{
public:
    PriorityQueue() : head(NULL) {}
    ~PriorityQueue()
    {
        delete head;
    }
    /** adds element to the queue with its priority */
    void enqueue(T item, unsigned int priority);
    /** returns element that has maximum priority and then deletes it */
    T dequeue() throw (QueueIsEmptyExc*);
    QueueElement<T> *getHead()
    {
        return head;
    }
private:
    QueueElement<T> *head;
};

template <typename T>
void PriorityQueue<T>::enqueue(T item, unsigned int priority)
{
    QueueElement<T> *newElem = new QueueElement<T>(item, priority);
    if (head != NULL)
    {
        if (head->getPriority() >= priority)
        {
            QueueElement<T> *temp = head;
            while (temp->getNext() != NULL)
            {
                if (temp->getPriority() >= priority)
                {
                    temp = temp->getNext();
                }
                else
                {
                    newElem->setPrev(temp);
                    newElem->setNext(temp->getNext());
                    temp->getNext()->setPrev(newElem);
                    temp->setNext(newElem);
                    break;
                }
            }
            if (temp->getPriority() >= priority)
            {
                temp->setNext(newElem);
                newElem->setPrev(temp);
            }
            else
            {
                newElem->setPrev(temp->getPrev());
                newElem->setNext(temp);
                temp->getPrev()->setNext(newElem);
                temp->setPrev(newElem);
            }
        }
        else
        {
            newElem->setNext(head);
            head->setPrev(newElem);
            head = newElem;
        }
    }
    else
    {
        head = newElem;
    }
}

template <typename T>
T PriorityQueue<T>::dequeue() throw(QueueIsEmptyExc*)
{
    if (head != NULL)
    {
        unsigned int valueToReturn = head->getItem();
        QueueElement<T> *temp = head;
        head = head->getNext();
        temp->setNext(NULL);
        delete temp;
        return valueToReturn;
    }
    else
    {
        throw new QueueIsEmptyExc("Queue is Empty!");
    }
}
