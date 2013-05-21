#include "AVLTreeTest.h"
#include "BagTest.h"
#include "AVLTreeIteratorTest.h"
#include "BagIteratorTest.h"

int main()
{
    AVLTreeTest testTree;
    QTest::qExec(&testTree);
    AVLTreeIteratorTest treeIterTest;
    QTest::qExec(&treeIterTest);
    BagTest testBag;
    QTest::qExec(&testBag);
    BagIteratorTest bagIterTest;
    QTest::qExec(&bagIterTest);
}
