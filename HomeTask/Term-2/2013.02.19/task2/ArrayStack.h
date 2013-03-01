#pragma once
#include "Stack.h"

class ArrayStack : public Stack
{
public:
    int pop ();
    void push (int value);
    int top ();
    ArrayStack();
    ~ArrayStack();
private:
    int *array;
    const int additionalSize;
    int currentSize;
    bool isEmpty();
    void checkOverFlow();
};
