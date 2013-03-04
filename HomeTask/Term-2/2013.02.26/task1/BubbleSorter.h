#pragma once
#include "Sorter.h"

class BubbleSorter : public Sorter
{
public:
    BubbleSorter(int *arrayToSort, int size);
    ~BubbleSorter();
    void sort();
private:
    void bSort(int *arr, int arrSize);
};
