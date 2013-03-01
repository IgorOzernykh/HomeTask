#pragma once
#include "Stack.h"
#include <stdlib.h>

class LinkedStack : public Stack
{
public:
    int pop ();
    void push (int value);
    int top ();

    LinkedStack();
    ~LinkedStack();
private:
    struct StackElement;
    StackElement *head;
    bool isEmpty();
};

