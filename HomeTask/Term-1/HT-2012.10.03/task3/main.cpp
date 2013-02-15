#include "task3.h"
#include <iostream>
using std::cout;
using std::cin;
char menu()
{
	char key;
	cout << "\n0 - exit\n"
		 << "1 - add value to sorted list\n"
		 << "2 - remove value from list\n"
		 << "3 - print list\n\n";
	while (1)
	{
		cin >> key;
		if (key == '0' || key == '1' || key == '2' || key == '3')
			break;
		else cout << "Incorrect input\n\n";
	}
	return key;
}
int main()
{
	List *list = createList();
	int size =0;
	char key = 'x';
	while (key != '0')
	{
		key = menu();
		if (key == '1')
		{
			int value;
			cout << "\nEnter value\n";
			cin >> value;
			add(list, value);
		}
		else if (key == '2')
		{
			int value;
			cout << "\nEnter value\n";
			cin >> value;
			deleteValue(list, value);
		}
		else if (key == '3')
		{
			printList(list);
		}
	}
	if (key == '0')
		cout << "\nProgram has finished\n";
	deleteList(list);
	delete list->head;
	int x;
	cin >> x;
}