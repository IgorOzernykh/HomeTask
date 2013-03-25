//#include <iostream>
//#include "HashTableManager.h"
//using namespace std;

//int main()
//{
//    HashTableManager *HTmanager = new HashTableManager;
//    HTmanager->dialog();
//    delete HTmanager;
//    cout << "Program has finished." << endl;
//}

#include "ListTest.h"
#include "HashTableTest.h"
int main()
{
    QObject *ltest = new ListTest();//ListTest ltest;
    QTest::qExec(ltest);
    /*QObject *htest = new HashTableTest();
    QTest::qExec(htest)*/;
    HashTableTest htest;
    QTest::qExec(&htest);
}
