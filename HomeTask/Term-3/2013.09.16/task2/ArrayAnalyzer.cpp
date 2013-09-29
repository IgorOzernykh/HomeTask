#include "ArrayAnalyzer.h"

ArrayAnalyzer::ArrayAnalyzer(QVector<double> arrayToAnalyze) :
    array(arrayToAnalyze),
    nullElemCounter(0)
{
}

unsigned int ArrayAnalyzer::getAmountOfNullElems()
{
    int arraySize = array.size();
    for (int i = 0; i < arraySize; i++)
    {
        if (array.at(i) == 0)
        {
            nullElemCounter++;
        }
    }
    return nullElemCounter;
}
