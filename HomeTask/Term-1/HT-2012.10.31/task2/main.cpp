#include "hashTable.h"
#include <string.h>
#include <iostream>
#include <fstream>

int main()
{
	char filename[100];
	std::cout << "Enter file name: ";
	std::cin >> filename;
	std::ifstream file(filename);
	if (file != nullptr)
	{
		char ch;
		char *word = new char[100];
		unsigned long long int tableSize = 1000;
		HTable *table = createHTable(tableSize);
		double loadFactor = 0;
		unsigned long long int quantityOfWords = 0;
		while (!file.eof())
		{
			ch = file.get();
			int i = 0;
			while (!(file.eof()) && ch != ' ' && ch != '.' && ch != ',' && ch != '?' 
				&& ch != '!' && ch != '"' && ch != '\n' && ch != ':' && ch != '(' && ch != ')' && ch != ';')
			{
				word[i] = ch;
				i++;
				ch = file.get();
			}
			word[i] = '\0';
			add(table, word, loadFactor);
			quantityOfWords++;
			if (loadFactor > 0.6)
			{
				loadFactor = 0;
				table = rebuildTable(table, tableSize, loadFactor);
			}
		}
		delete []word;
		printTableAndStatistics(table, tableSize, quantityOfWords);
		destroyTable(table, tableSize);
		file.close();
	}
	else 
		std::cout << "File is not open\n";
	char exit;
	std::cout << "\nEnter any character to exit: ";
	std::cin >> exit;
}