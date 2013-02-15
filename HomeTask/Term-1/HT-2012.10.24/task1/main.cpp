#include <iostream>
#include "bst.h"
using std::cout;
using std::cin;

char menu()
{
	char key;
	cout << "\n0 - exit\n"
		 << "1 - add value to the set\n"
		 << "2 - remove value from the set\n"
		 << "3 - print set in ascending order\n"
		 << "4 - print set in descending order\n\n";
	while (1)
	{
		cin >> key;
		if (key == '0' || key == '1' || key == '2' || key == '3' || key == '4')
			break;
		else cout << "\nIncorrect input\n\n";
	}
	return key;
}


int main()
{
	Tree *tree = createTree();
	char key = 'x';
	while (key != '0')
	{
		key = menu();
		if (key == '1')
		{
			int value;
			cout << "\nEnter value: ";
			cin >> value;
			add(tree, value);
		}
		else if (key == '2')
		{
			int value;
			cout << "\nEnter value: ";
			cin >> value;
			remove(tree, value);
		}
		else if (key == '3')
		{
			printInAscendingOrder(tree);
			cout << "\n";
		}
		else if (key == '4')
		{
			printInDescendingOrder(tree);
			cout << "\n";
		}
	}
	if (key == '0')
		cout << "\nProgram has finished\n\n";
	
	destroyTree(tree);
	delete tree;
    char ch;
	cout << "Enter any character: ";
    cin >> ch;
}
