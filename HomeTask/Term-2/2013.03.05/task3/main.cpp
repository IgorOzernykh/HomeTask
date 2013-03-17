//#include <QtGui/QApplication>
//#include "UberCalc.h"

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    UberCalc w;
//    w.show();
    
//    return a.exec();
//}

#include "CalculatorTest.h"

int main()
{
    CalculatorTest test;
    QTest::qExec(&test);
}
