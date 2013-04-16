#include <QtGui/QApplication>
#include "OuthAndCrosses.h"
#include "EndGameTest.h"

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    OuthAndCrosses w;
//    w.show();
    
//    return a.exec();

    EndGameTest test;
    QTest::qExec(&test);
}
