#pragma once
#include "Printer.h"

/** PrintInConsole implementation class;
    Inherited from interface; */

class PrintInConsole : public Printer
{
private:
    /** Implementation of function print in console */
    void print(int *array, int size);
};

