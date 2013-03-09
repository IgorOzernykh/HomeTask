#include "PrintInFile.h"

void PrintInFile::print (int *array, int size)
{
    ofstream file("output.txt");
    for (int i = 0; i < size; i++)
    {
        file << array[i] << " ";
    }
    file << endl;
    file.close();
}
