#pragma once
#include "Printer.h"

/** PrintInFile implementation class;
    Inherited from interface; */

class PrintInFile : public Printer
{
private:
    /** Implementation of function print in file.
    Output file is "output.txt". */
    void print(int *array, int size);
};
