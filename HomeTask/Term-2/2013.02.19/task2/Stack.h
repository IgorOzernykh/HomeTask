#pragma once
#include <iostream>
using std::string;

class Stack
{
public:
    virtual int pop() = 0;
    virtual void push(int value) = 0;
    virtual int top () = 0;

    Stack();
    virtual ~Stack();
protected:
    int elementsCounter;
    virtual bool isEmpty() = 0;
public:
    int Calculator(string s);
};


