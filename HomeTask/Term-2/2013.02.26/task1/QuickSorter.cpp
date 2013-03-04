#include "QuickSorter.h"

QuickSorter::QuickSorter(int *arrayToSort, int size) :
    Sorter(arrayToSort, size)
{
}

QuickSorter::~QuickSorter()
{
}


void QuickSorter::qSort (int *arr, int low, int high)
{
    int i = low;
    int j = high;
    int m = arr[(low + high) / 2];
    while (i <= j)
    {
        while (arr[i] < m)
            i++;
        while (arr[j] > m)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (low < j)
        qSort(arr, low, j);
    if (i < high)
        qSort(arr, i, high);
}

void QuickSorter::sort()
{
    const int start = 0;
    qSort (array, start, arraySize - 1);
}
