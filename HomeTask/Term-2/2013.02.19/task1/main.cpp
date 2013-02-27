#include <iostream>
#include "PointerList.h"
#include "ArrayList.h"

using namespace std;


void addElements(List *list)
{
    list->add(4);
    list->add(7);
    list->add(7);
    list->add(7);
    list->add(7);
    list->add(7);
    list->add(5);
    list->add(8);
    list->add(20);
    list->add(32);
}

void test(List *plist, List *alist)
{
    cout << "Adding elements:" << endl;
    addElements(plist);
    addElements(alist);
    plist->show();
    alist->show();

    cout << "Removing elements: " << endl;
    plist->remove(4);
    alist->remove(4);
    plist->remove(7);
    alist->remove(7);
    plist->remove(11);
    alist->remove(11);
    plist->remove(32);
    alist->remove(32);

    alist->show();
    plist->show();


}

int main()
{
    List *plist = new PointerList;
    List *alist = new ArrayList;

    test(plist, alist);

    delete plist;
    delete alist;

    char exit;
    std::cout << "\nEnter any character to exit: ";
    std::cin >> exit;
}

