#include "HeapSorter.h"

HeapSorter::HeapSorter(int *arrayToSort, int size) :
    Sorter(arrayToSort, size)
{
}

void HeapSorter::downheap(int *arr, int i, int n)
{
    int child;
    while (i <= n / 2)
    {
        child = 2 * i;
        if (child < n)
        {
            if (arr[child + 1] < arr[child + 2])
            {
                child += 2;
            }
            else
                child++;
        }
        if (child > n)
            child--;
        if (arr[i] > arr[child])
            break;
        swap(arr[i], arr[child]);
        i = child;
    }
}
void HeapSorter::hSort(int *arr, int n)
{
    if (n == 1)
        return;
    for (int i = n / 2; i >= 0; i--)
        downheap(arr, i, n - 1);
    for (int i = n - 2; i > 0; i--)
    {
        swap(arr[0], arr[i + 1]);
        downheap(arr, 0, i);
    }
    swap(arr[0], arr[1]);
}

void HeapSorter::sort()
{
    hSort(array, arraySize);
}
