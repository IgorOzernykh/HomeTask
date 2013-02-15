#include "HTable.h"
#include <string.h>
#include <iostream>
#include <fstream>

int main()
{
	const int strsize = 1000;
	std::ifstream fileF("f.txt");
	std::ifstream fileG("g.txt");
	std::ofstream fileH("h.txt");
	if (fileF != nullptr && fileG != nullptr)
	{
		double loadFactor = 0;
		unsigned long long int tableSize = 50;
		HTable *table = createHTable(tableSize);
		char *str = new char [strsize];
		while (!fileF.eof())
		{
			fileF.getline(str, strsize);
			add(table, str, loadFactor);
			if (loadFactor > 0.9)
			{
				loadFactor = 0;
				table = rebuildTable(table, tableSize, loadFactor);
			}
		}
		while (!fileG.eof())
		{
			fileG.getline(str, strsize);
			if (isInTable (table, tableSize, str))
			{
				fileH << str << "\n";
			}
		}
		delete []str;
		fileF.close();
		fileG.close();
		fileH.close();
		destroyTable(table, tableSize);
	}
	else 
		std::cout << "Files are not open\n";
	char exit;
	std::cout << "\nProgram has finished. Enter any character to exit: ";
	std::cin >> exit;
}