#pragma once
#include "Sorter.h"

class HeapSorter : public Sorter
{
public:
    HeapSorter(int *arrayToSort, int size);
    ~HeapSorter();
    void sort();
private:
    void downheap(int *arr, int i, int n);
    void hSort(int *array, int n);
};


