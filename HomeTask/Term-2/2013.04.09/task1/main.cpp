#include "AVLTreeTest.h"
#include "BagTest.h"

int main()
{
    AVLTreeTest testTree;
    QTest::qExec(&testTree);
    BagTest testBag;
    QTest::qExec(&testBag);
}
