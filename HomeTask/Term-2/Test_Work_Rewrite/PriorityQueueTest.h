#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "PriorityQueue.h"

class PriorityQueueTest : public QObject
{
    Q_OBJECT
private:
    PriorityQueue<int> *pqueue;
private slots:
    void init()
    {
        pqueue = new PriorityQueue<int>();
    }
    void enqueueTest()
    {
        pqueue->enqueue(223, 3);
        pqueue->enqueue(3, 43);
        pqueue->enqueue(145, 32);
        pqueue->enqueue(23, 45);
        pqueue->enqueue(83, 76);
        pqueue->enqueue(234, 32);
        QueueElement<int> *temp = pqueue->getHead();
        QVERIFY(temp->getItem() == 83);
        temp = temp->getNext();
        QVERIFY(temp->getItem() == 23);
        temp = temp->getNext();
        QVERIFY(temp->getItem() == 3);
        temp = temp->getNext();
        QVERIFY(temp->getItem() == 145);
        temp = temp->getNext();
        QVERIFY(temp->getItem() == 234);
        temp = temp->getNext();
        QVERIFY(temp->getItem() == 223);
    }
    void dequeueTest()
    {
        pqueue->enqueue(223, 3);
        pqueue->enqueue(3, 43);
        pqueue->enqueue(145, 32);
        pqueue->enqueue(23, 45);
        pqueue->enqueue(83, 76);
        pqueue->enqueue(234, 32);
        try
        {
            QVERIFY(pqueue->dequeue() == 83);
            QVERIFY(pqueue->dequeue() == 23);
            QVERIFY(pqueue->dequeue() == 3);
            QVERIFY(pqueue->dequeue() == 145);
            QVERIFY(pqueue->dequeue() == 234);
            QVERIFY(pqueue->dequeue() == 223);
        }
        catch (std::exception *exc)
        {
            delete exc;
            QFAIL("");
        }
    }
    void dequeueFromEmptyQueueTest()
    {
        try
        {
            pqueue->dequeue();
            QFAIL("");
        }
        catch (std::exception *exc)
        {
            QVERIFY(std::string(exc->what()) == std::string("Queue is Empty!"));
        }
    }
    void cleanup()
    {
        delete pqueue;
    }
};
