#pragma once
#include "Comparer.h"

/** Template BubbleSorter class. Use Comparer's function to compare elements of different types */

template <typename T>
class BubbleSorter
{
public:
    static void bSort(T *arr, int arrSize)
    {
        for (int i = 0; i < arrSize - 1; i++)
        {
            for (int j = i + 1; j < arrSize; j++)
            {
                if (Comparer<T>::compare(arr[i], arr[j]) == 1)
                {
                    T temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
};



