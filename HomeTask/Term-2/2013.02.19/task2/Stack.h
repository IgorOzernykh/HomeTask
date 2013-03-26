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
    virtual bool isEmpty() = 0;
protected:
    int elementsCounter;
public:
    int Calculator(string s);
};


