#include "Sorter.h"


Sorter::Sorter(int *arrayToSort, int size)
{
    arraySize = size;
    array = new int [arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = arrayToSort[i];
    }
}
Sorter::~Sorter()
{
    delete []array;
}

void Sorter::print()
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
