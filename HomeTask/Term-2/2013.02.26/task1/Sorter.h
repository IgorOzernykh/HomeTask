#pragma once
#include <iostream>

using namespace std;

class Sorter
{
public:
    Sorter(int *arrayToSort, int size);
    virtual ~Sorter();
    virtual void sort() = 0;
    void print();
protected:
    void swap(int &a, int &b);
    int *array;
    int arraySize;
};


