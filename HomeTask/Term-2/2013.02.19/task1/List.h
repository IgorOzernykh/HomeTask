#pragma once
#include <iostream>
using namespace std;

class List
{
public:
    virtual void add(int value) throw (string) = 0;
    virtual void remove(int value) throw (string) = 0;
    virtual void show() throw (string) = 0;
    virtual int &operator[](int index) = 0;
    List();
    virtual ~List();
protected:
    int elementsCounter;
};

