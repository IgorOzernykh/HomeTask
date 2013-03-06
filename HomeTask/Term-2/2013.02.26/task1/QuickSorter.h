#pragma once
#include "Sorter.h"

/** QuickSort implementation class;
    Inherited from interface; */

class QuickSorter : public Sorter
{
public:
    QuickSorter(int *arrayToSort, int size);
    void sort();
    /** Implementation of function that calls Quick Sorting */
private:
    void qSort(int *array, int start, int end);
    /** Implementation of Quick Sorting */
};
