#pragma once

class List
{
public:
    virtual void add(int value) = 0;
    virtual void remove(int value) = 0;
    virtual void show() = 0;
    List();
    virtual ~List();
protected:
    int elementsCounter;
};

