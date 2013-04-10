#include "TreeTest.h"
#include "SetTest.h"
#include <iostream>

int main()
{
    TreeTest test1;
    QTest::qExec(&test1);
    SetTest test2;
    QTest::qExec(&test2);
}
