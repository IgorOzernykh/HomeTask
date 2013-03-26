#pragma once
#include <iostream>

using namespace std;
/**
    Sorter Class interface;
    You can inherit other sort classes from this; */
class Sorter
{
public:
    Sorter(int *arrayToSort, int size);
    /** Constructor for regular sorter class; */
    virtual ~Sorter();
    /** Destructor deletes internal array; */
    virtual void sort() = 0;
    /** Function that calls the sort function in each inherited class; */
    void print();
    /** Function that prints array; */
//protected:
    int *array;
    int arraySize;
};


