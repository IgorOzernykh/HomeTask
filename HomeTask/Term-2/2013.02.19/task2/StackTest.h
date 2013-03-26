#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "ArrayStack.h"
#include "LinkedStack.h"

class StackTest : public QObject
{
    Q_OBJECT
private:
    Stack *lstack;
    Stack *astack;
private slots:
    void init()
    {
        lstack = new LinkedStack;
        astack = new ArrayStack;
    }
    void testIsEmpty()
    {
        QVERIFY(lstack->isEmpty() == true);
        QVERIFY(astack->isEmpty() == true);
    }

    void testPushAndTop()
    {
        lstack->push(1);
        QVERIFY(lstack->top() == 1);

        astack->push(1);
        QVERIFY(astack->top() == 1);
    }
    void testPop()
    {
        lstack->push(1);
        QVERIFY(lstack->pop() == 1);
        QVERIFY(lstack->isEmpty());

        astack->push(1);
        QVERIFY(astack->pop() == 1);
        QVERIFY(astack->isEmpty());
    }
    void testCorrectSequence()
    {
        lstack->push(1);
        lstack->push(2);
        lstack->push(3);
        QVERIFY(lstack->pop() == 3);
        QVERIFY(lstack->pop() == 2);
        QVERIFY(lstack->pop() == 1);

        astack->push(1);
        astack->push(2);
        astack->push(3);
        QVERIFY(astack->pop() == 3);
        QVERIFY(astack->pop() == 2);
        QVERIFY(astack->pop() == 1);
    }
    void calculatorTest1()
    {
        QVERIFY(lstack->Calculator("12+3*1+2/") == 5);
    }
    void calculatorTest2()
    {
        QVERIFY(astack->Calculator("12+3*1+2/") == 5);
    }

    void cleanup()
    {
        delete lstack;
        delete astack;
    }
};
