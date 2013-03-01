#include <iostream>
#include "LinkedStack.h"
#include "ArrayStack.h"

using namespace std;

int main()
{
    Stack *lstack = new LinkedStack;
    Stack *astack = new ArrayStack;

    string expression;
    cout << "Enter an expression in reverse Poland notation:" << endl;
    getline(cin, expression);
    char key = 'x';
    cout << "Choose type of stack:" << endl << "1 - Linked stack" << endl << "2 - Array stack" << endl;
    cin >> key;
    cout << "Result = ";
    switch (key)
    {
        case '1':
            cout << lstack->Calculator(expression) << endl;
            break;
        case '2':
            cout << astack->Calculator(expression) << endl;
            break;
    }

    delete lstack;
    delete astack;
}

