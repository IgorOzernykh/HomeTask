#include "QuickSorter.h"
#include "BubbleSorter.h"
#include "HeapSorter.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

void generateArray (int *array, int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand()%100 - 50;
    }
}

void SortAndPrint(Sorter *object)
{
    cout << "Basic array:" << endl;
    object->print();
    cout << endl;
    object->sort();
    cout << "Sorted array:" << endl;
    object->print();
    cout << endl;
}

void test(Sorter *bObject, Sorter *qObject, Sorter *hObject)
{
    cout << "BubbleSort:" << endl;
    SortAndPrint(bObject);
    cout << "QuickSort:" << endl;
    SortAndPrint(qObject);
    cout << "HeapSort:" << endl;
    SortAndPrint(hObject);
}

int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;
    int *array = new int [size];
    generateArray(array, size);

    Sorter *bObject = new BubbleSorter(array, size);
    Sorter *qObject = new QuickSorter(array, size);
    Sorter *hObject = new HeapSorter(array, size);

    test(bObject, qObject, hObject);

    delete bObject;
    delete qObject;
    delete hObject;
    delete []array;

}
