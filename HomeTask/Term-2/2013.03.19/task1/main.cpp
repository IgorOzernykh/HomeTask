#include "Tree.h"
#include <iostream>
#include "TreeTest.h"

int main()
{
    TreeTest treeTest;
    QTest::qExec(&treeTest);
    Tree *tree = new Tree();
    cout << endl;

    tree->parse("input.txt");
    cout << "Result = " << tree->calc();
    tree->print("output.txt");
    delete tree;
}
