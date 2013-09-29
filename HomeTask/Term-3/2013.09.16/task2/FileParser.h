#pragma once
#include <QVector>
#include <fstream>
#include "FileIsNotOpenedExc.h"

/** Creates array with data from file.
    Then returns QVector<double> */

class FileParser
{
public:
    FileParser(std::ifstream &file) throw (FileIsNotOpenedExc);
    QVector<double> getArray()
    {
        return array;
    }
private:
    unsigned int arraySize;
    QVector<double> array;
};


