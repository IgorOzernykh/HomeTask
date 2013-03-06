#include "Sorter.h"

Sorter::Sorter(int **arrayToSort, int rowCount, int columnCount)
{
    row = rowCount;
    column = columnCount;
    array = arrayToSort;
}

Sorter::~Sorter()
{
}

void Sorter::print()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
