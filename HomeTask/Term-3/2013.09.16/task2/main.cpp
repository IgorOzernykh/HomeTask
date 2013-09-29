#include <QtCore/QCoreApplication>
#include "FileParser.h"
#include "ArrayAnalyzer.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    try
    {
        std::ifstream file("test.txt");
        FileParser fileParser(file);
        file.close();
        ArrayAnalyzer arrayAnazyler(fileParser.getArray());
        std::cout << "Amount of null elements in array is " << arrayAnazyler.getAmountOfNullElems();
    }
    catch (std::exception)
    {
        FileIsNotOpenedExc exc;
        std::cout << exc.what();
    }
    return a.exec();
}
