#pragma once
#include "Sorter.h"

/** HeapSort implementation class;
    Inherited from interface; */

class HeapSorter : public Sorter
{
public:
    HeapSorter(int *arrayToSort, int size);
    void sort();
    /** Implementation of function that calls Heap Sorting */
private:
    void downheap(int *arr, int i, int n);
    /** Part of function hSort */
    void hSort(int *array, int n);
    /** Implementation of Heap Sorting */
};


