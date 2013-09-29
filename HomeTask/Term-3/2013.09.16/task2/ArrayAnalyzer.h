#pragma once
#include <QVector>

/** Analyzes amount of null elements in array */

class ArrayAnalyzer
{
public:
    ArrayAnalyzer(QVector<double> arrayToAnalyze);
    unsigned int getAmountOfNullElems();
private:
    QVector<double> array;
    unsigned int nullElemCounter;

};
