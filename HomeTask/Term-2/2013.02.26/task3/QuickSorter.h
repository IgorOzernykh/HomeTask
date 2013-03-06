#pragma once
#include "Sorter.h"

/** QuickSort implementation class;
    Inherited from interface; */

class QuickSorter : public Sorter
{
public:
    QuickSorter(int **arrayToSort, int rowCount, int columnCount);
    /** Implementation of function that calls Quick Sorting */
    void sort();
private:
    /** Implementation of Quick Sorting */
    void qSort(int **array, int start, int end);
};
