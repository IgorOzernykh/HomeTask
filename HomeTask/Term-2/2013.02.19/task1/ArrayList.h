#pragma once
#include "List.h"


class ArrayList : public List
{
public:
    void add(int value) throw (string);
    void remove(int value) throw (string);
    void show() throw (string);
    virtual int &operator[](int index);
    ArrayList();
    ~ArrayList();
private:
    int *array;
    const int additionalSize;
    int currentSize;
    void swap (int &a, int &b);
    void checkOverFlow();
};

