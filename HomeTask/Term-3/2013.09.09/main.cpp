//#include <QtGui/QApplication>
//#include "Dialog.h"

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    Dialog w;
//    w.show();
    
//    return a.exec();
//}

#include "NetworkTest.h"

int main()
{
    NetworkTest test;
    QTest::qExec(&test);
}
