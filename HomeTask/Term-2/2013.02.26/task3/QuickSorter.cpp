#include "QuickSorter.h"

QuickSorter::QuickSorter(int **arrayToSort, int rowCount, int columnCount) :
    Sorter(arrayToSort, rowCount, columnCount)
{
}

void QuickSorter::qSort (int **arr, int low, int high)
{
    const int firstElem = 0;
    int i = low;
    int j = high;
    int m = arr[(low + high) / 2][firstElem];
    while (i <= j)
    {
        while (arr[i][firstElem] < m)
            i++;
        while (arr[j][firstElem] > m)
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
    qSort (array, start, row - 1);
}
