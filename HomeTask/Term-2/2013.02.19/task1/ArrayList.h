#pragma once
#include "List.h"


class ArrayList : public List
{
public:
    void add(int value);
    void remove(int value);
    void show();
    ArrayList();
    ~ArrayList();
private:
    int *array;
    const int additionalSize;
    int currentSize;
    void swap (int &a, int &b);
    void checkOverFlow();
};

