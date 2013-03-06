#pragma once
#include "Sorter.h"

/** BubbleSort implementation class;
    Inherited from interface; */

class BubbleSorter : public Sorter
{
public:
    BubbleSorter(int *arrayToSort, int size);
    void sort();
    /** Implementation of function that calls Bubble Sorting */
private:
    void bSort(int *arr, int arrSize);
    /** Implementation of Bubble Sorting */
};
