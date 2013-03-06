#pragma once
#include <iostream>
using namespace std;

/**
    Sorter Class interface;
    You can inherit other sort classes from this; */

class Sorter
{
public:
    /** Constructor for sorting array */
    Sorter(int **arrayToSort, int rowCount, int columnCount);
    virtual ~Sorter();
    /** Function that calls any sorting function */
    virtual void sort() = 0;
    /** Function that prints array */
    void print();
protected:
    int **array;
    int row;
    int column;
};


