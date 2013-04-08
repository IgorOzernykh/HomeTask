#include "TreeTest.h"
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

char menu()
{
    char key;
    cout << endl << "0 - exit" << endl
         << "1 - add item to the set" << endl
         << "2 - remove item from the set" << endl
         << "3 - is exist in tree" << endl
         << "4 - is exist in intersection" << endl
         << "5 - is exist in unification" << endl << endl;
    while (1)
    {
        cin >> key;
        if (key == '0' || key == '1' || key == '2' || key == '3' || key == '4' || key == '5')
            break;
        else cout << endl << "Incorrect input" << endl << endl;
    }
    return key;
}

int main()
{
    TreeTest test;
    QTest::qExec(&test);
    BinarySearchTree<int> *tree1 = new BinarySearchTree<int>();
    BinarySearchTree<int> *tree2 = new BinarySearchTree<int>();
    BinarySearchTree<int> *tree = NULL;
    char key = 'x';
    while (key != '0')
    {
        char treeChoose = 'x';
        cout << endl << "Choose the tree you want to do operations with (1 or 2)" << endl;
        cin >> treeChoose;
        switch (treeChoose)
        {
        case '1':
            tree = tree1;
            break;
        case '2':
            tree = tree2;
            break;
        }
        key = menu();
        int value;
        switch (key)
        {
        case '1':
            cout << endl << "Enter value you want to add: ";
            cin >> value;
            try
            {
                tree->add(value);
            }
            catch (exception)
            {
                AlreadyExistExc exc;
                cout << exc.what() << endl;
            }
            break;
        case '2':
            cout << endl << "Enter value you want to remove: ";
            cin >> value;
            try
            {
                tree->remove(value);
            }
            catch(exception *exc)
            {
                cout << exc->what() << endl;
                delete exc;
            }
            break;
        case '3':
            cout << endl << "Enter value you want to search: ";
            cin >> value;
            if (tree->isExistInTree(value))
                cout << "Value exists in tree!" << endl;
            else
                cout << "Value does not exist in tree!" << endl;
            break;
        case '4':
            cout << endl << "Enter value you want to search: ";
            cin >> value;
            if (tree1->isExistInTree(value) || tree2->isExistInTree(value))
                cout << "Value exists in intersection!" << endl;
            else
                cout << "Value does not exist in intersection!" << endl;
            break;
        case '5':
            cout << endl << "Enter value you want to search: ";
            cin >> value;
            if (tree1->isExistInTree(value) && tree2->isExistInTree(value))
                cout << "Value exists in unification!" << endl;
            else
                cout << "Value does not exist in unification!" << endl;
            break;
        case '0':
            cout << endl << "Program has finished" << endl;
            break;
        }
    }

    delete tree1;
    delete tree2;
}

