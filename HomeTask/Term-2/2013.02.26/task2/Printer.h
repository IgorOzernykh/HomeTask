#pragma once
#include <iostream>
#include <fstream>

using namespace std;

/**
    Printer Class interface;
    You can inherit other classes from this
    with deffrent implementations of printers; */

class Printer
{
public:
    /** Virtual function that prints array. Implemented in inherited classes */
    virtual void print(int *array, int size) = 0;
};

