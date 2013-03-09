#include "ByPass.h"

int *ByPass::SpiralByPass(int **arr, int size)
{
    int *byPassArray = new int[size * size];
    int elementCounter = 0;
    int i = size / 2;
    int j = size / 2;
    byPassArray[elementCounter++] = arr[i][j];
    int numStep = 1;
    int stepSize = 1;
    const int startByPass = 1;
    for (int k = startByPass; k <= size / 2; k++)
    {
        const int start = 0;
        if (numStep % 2 == 1 && stepSize % 2 == 1)
        {
            for (int l = start; l < stepSize; l++)
            {
                j++;
                byPassArray[elementCounter++] = arr[i][j];
            }
            numStep++;
        }
        if (numStep % 2 == 0 && stepSize % 2 == 1)
        {
            for (int l = start; l < stepSize; l++)
            {
                i++;
                byPassArray[elementCounter++] = arr[i][j];
            }
            numStep++;
            stepSize++;
        }
        if (numStep % 2 == 1 && stepSize % 2 == 0)
        {
            for (int l = start; l < stepSize; l++)
            {
                j--;
                byPassArray[elementCounter++] = arr[i][j];
            }
            numStep++;
        }
        if (numStep % 2 == 0 && stepSize % 2 == 0)
        {
            for (int l = start; l < stepSize; l++)
            {
                i--;
                byPassArray[elementCounter++] = arr[i][j];
            }
            numStep++;
            stepSize++;
        }
    }
    const int firstNotPrintedElementInFirstLine = 1;
    for (int k = firstNotPrintedElementInFirstLine; k < size; k++)
    {
        byPassArray[elementCounter++] = arr[i][k];
    }
    return byPassArray;
}
