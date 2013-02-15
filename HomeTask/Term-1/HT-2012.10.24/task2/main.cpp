#include <iostream>
#include <stdio.h>
#include <string.h>
#include "6-2.h"
int main()
{
	std::cout << "Enter file name: ";
	char filename[1000];
	std::cin >> filename;
	FILE *f = fopen(filename, "r");
	char str[1000];
	int value;
	Tree *tree = createTree();
	if (f != NULL)
	{
		fgets(str, sizeof(str), f);
		int len = strlen(str);
		for (int i = 0; i < len; i++)
		{
			if (str[i] != ' ' && str[i] != '(' && str[i] != ')')
			{
				if (str[i] >= '0' && str[i] <= '9')
					addValue(tree, str[i] - '0');
				else
					addSymbol(tree, str[i]);
			}
		}
		print(tree);
		std::cout << "\n";
		value = result(tree);
		std::cout << "Result = " << value << "\n";
	}
	else 
		std::cout << "File is not open.\n";
	delete tree;
	char ch;
	std::cout << "Enter any character to exit: ";
	std::cin >> ch;
}