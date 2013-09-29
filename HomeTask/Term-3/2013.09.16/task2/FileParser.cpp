#include "FileParser.h"

FileParser::FileParser(std::ifstream &file) throw (FileIsNotOpenedExc) :
    arraySize(0)
{
    if (file.is_open())
    {
        file >> arraySize;
        for (unsigned int i = 0; i < arraySize; i++)
        {
            double value = 0;
            file >> value;
            array.append(value);
        }
    }
    else
    {
        throw FileIsNotOpenedExc();
    }
}

