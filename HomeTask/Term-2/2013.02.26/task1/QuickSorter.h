#pragma once
#include "Sorter.h"

class QuickSorter : public Sorter
{
public:
    QuickSorter(int *arrayToSort, int size);
    ~QuickSorter();
    void sort();
private:
    void qSort(int *array, int start, int end);
};
