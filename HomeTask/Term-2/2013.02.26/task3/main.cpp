//#include "QuickSorter.h"

//using namespace std;

//int **generateArray(int row, int column)
//{
//    int **array = new int *[row];
//    for (int i = 0; i < row; i++)
//    {
//        array[i] = new int[column];
//        for (int j = 0; j < column; j++)
//        {
//            array[i][j] = rand() % 50 + 10;
//        }
//    }
//    return array;
//}

//void destroyArray(int **array, int row)
//{
//    for (int i = 0; i < row; i++)
//    {
//        delete []array[i];
//    }
//    delete []array;
//}

//int main()
//{
//    int column;
//    int row;
//    cout << "Enter the quantity of rows:  ";
//    cin >> row;
//    cout << "Enter the quantity of columns: ";
//    cin >> column;

//    int **array = generateArray(row, column);

//    QuickSorter arraySorter(array, row, column);

//    cout << "Basic array:" << endl;
//    arraySorter.print();

//    arraySorter.sort();

//    cout << "Sorted array:" << endl;
//    arraySorter.print();

//    destroyArray(array, row);
//}

#include "SorterTest.h"
int main()
{
    SorterTest test;
    QTest::qExec(&test);
}
