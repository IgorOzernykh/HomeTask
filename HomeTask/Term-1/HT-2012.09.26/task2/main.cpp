#include <iostream>
#include "task2.h"

int main()
{
	bool f = false;
	int size;
	std::cout << "Enter the amout of numbers: ";
	std::cin >> size;
	int position;
	std::cout << "Enter Position: ";
	std::cin >> position;
	for (int k = 2; k <= size; k++)
	{
		List *cycle = fillList(size);
		delK(cycle, k);
		if (position == cycle->head->value)
		{
			if (!f)
				std::cout << "k = ";
			if (f)
				std::cout << "or k = ";
			f = true;
			std::cout << k << " ";
		}
		delete cycle->head;
		delete cycle;
	}
	if (!f)
		std::cout << "No such k.";
	std::cout << "\n";
	char exit;
	std::cout << "\nEnter any character to exit: ";
	std::cin >> exit;}