#include "BubbleSorter.h"

BubbleSorter::BubbleSorter(int *arrayToSort, int size) :
    Sorter(arrayToSort, size)
{
}

void BubbleSorter::bSort(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize - 1; i++)
    {
        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

void BubbleSorter::sort()
{
    bSort(array, arraySize);
}
