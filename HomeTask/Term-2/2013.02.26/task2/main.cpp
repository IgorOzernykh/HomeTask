#include "PrintInConsole.h"
#include "PrintInFile.h"
#include "ByPass.h"
#include <stdlib.h>
#include <time.h>

int **generateArray(int size)
{
    srand(time(0));
    int **array = new int *[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            array[i][j] = rand() % 50 + 10;
        }
    }
    return array;
}

void destroyArray(int **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete []array[i];
    }
    delete []array;
}

void printInitialArray (int **array, int size)
{
    cout << "Initial array:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size (odd number) of square array:" << endl;
    cin >> size;
    while (size % 2 != 1)
    {
        cout << "Error! Enter correct (odd) number!" << endl;
        cin >> size;
    }
    int **array = generateArray(size);
    printInitialArray(array, size);

    ByPass *SpiralInLineArray = new ByPass;
    int *arrayToPrint = SpiralInLineArray->SpiralByPass(array, size);
    delete SpiralInLineArray;

    int decision;
    cout << "Where do you want to print array?" << endl
         << "1 - In Console" << endl
         << "2 - In File" << endl;
    cin >> decision;
    switch (decision)
    {
        case 1:
        {
            Printer *printInConsole = new PrintInConsole;
            printInConsole->print(arrayToPrint, size*size);
            delete printInConsole;
            break;
        }
        case 2:
        {
            Printer *printInFile = new PrintInFile;
            printInFile->print(arrayToPrint, size*size);
            delete printInFile;
            break;
        }
    }

    delete []arrayToPrint;
    destroyArray(array, size);
}
