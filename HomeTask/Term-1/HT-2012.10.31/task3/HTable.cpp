#include "HTable.h"
#include <string.h>
#include <iostream>
#include <limits.h>

HTable *createHTable(unsigned long long int size)
{
	HTable *temp = new HTable;
	HTableElement *table = new HTableElement [size];
	for (int i = 0; i < size; i++)
	{
		table[i].word = nullptr;
		table[i].quantity = 0;
	}
	temp->table = table;
	temp->size = size;
	return temp;
}

unsigned long long int hash1 (unsigned long long int size, char *s)
{
	const int base = 13;
	unsigned long long int factor = 1;
	unsigned long long int hash = 0;
	int i = 0;
	while (s[i] != '\0')
	{
		hash += int (s[i]) * factor;
		factor *= base;
		i++;
	}
	return hash % (size / 2);
}
unsigned long long int hash2 (unsigned long long int size, char *s)
{
	int len = strlen(s);
	unsigned long long int pow = 1;
	const int p = 1028201;
	unsigned long long int hash = 0;
	for(int i = 0; i < len; i++)
	{
		hash += s[i]*pow;
		hash ^= 0xD32DE03A;
		pow *= p;
	}
	return hash % (size / 2) + size / 2;
}

void addElement (HTableElement &table, char *word, int quantity)
{
	table.word = strdup (word);
	table.quantity = quantity;
}

void addHash1 (HTable *table, char *word, int quantity, double &loadFactor)
{
	unsigned long long int pos = hash1 (table->size, word);
	if (table->table[pos].word == nullptr)
	{
		addElement (table->table[pos], word, quantity);
		loadFactor += (double(1) / table->size);
	}
	else if (strcmp(table->table[pos].word, word) == 0)
	{
		table->table[pos].quantity += quantity;
	}
	else 
	{
		char *tempWord = strdup (table->table[pos].word);
		int tempQuantity = table->table[pos].quantity;
		delete []table->table[pos].word;
		addElement(table->table[pos], word, quantity);
		addHash2(table, tempWord, tempQuantity, loadFactor, pos);
		delete []tempWord;
		
	}
}

void addHash2 (HTable *table, char *word, int quantity, double &loadFactor, unsigned long long int index)
{
	unsigned long long int pos = hash2 (table->size, word);
	if (table->table[pos].word == nullptr)
	{
		addElement (table->table[pos], word, quantity);
		loadFactor += (double(1) / table->size);
	}
	else if (strcmp(table->table[pos].word, word) == 0)
	{
		table->table[pos].quantity += quantity;
	}
	else 
	{
		if (index == pos)
		{
			loadFactor = 0;
			table = rebuildTable (table, table->size, loadFactor);
			addHash1 (table, word, quantity, loadFactor);
		}
		else
		{
			index = pos;
			char *tempWord = strdup (word);
			int tempQuantity = table->table[pos].quantity;
			delete []table->table[pos].word;
			addElement(table->table[pos], word, quantity);
			addHash2(table, tempWord, tempQuantity, loadFactor, index);
			delete []tempWord;
		}
	}
}

void printTableAndStatistics(HTable *table, unsigned long long int tableSize, unsigned long long int quantityOfWords)
{
	int filled = 0;
	int empty = 0;
	for (unsigned long long int i = 0; i < tableSize; i++)
		if (table->table[i].quantity != 0)
		{
			std::cout << table->table[i].word << " - " <<table->table[i].quantity << "\n";
			filled++;
		}
		else 
			empty++;
	double loadFactor = double(filled) / tableSize;
	std::cout << "Quantity of filled cells = " << filled << "\n"
			  << "Quantity of empty cells = " << empty << "\n"
			  << "Quantity of words = " << quantityOfWords << "\n"
			  << "Load factor = " << loadFactor << "\n";
}

void destroyTable(HTable *table, unsigned long long int size)
{
	for (unsigned long long int i = 0; i < size; i++)
	{
		if (table->table[i].word != nullptr)
			delete []table->table[i].word;
	}
	delete []table->table;
	delete table;
}

HTable *rebuildTable (HTable *table, unsigned long long int &size, double &loadFactor)
{
	unsigned long long int newsize;
	if (ULLONG_MAX - size > size)
		newsize = size * 2;
	else 
		newsize = ULLONG_MAX;
	HTable *newtable = createHTable(newsize);
	for (unsigned long long int i = 0; i < size; i++)
	{
		if (table->table[i].word != nullptr)
		{
			addHash1 (newtable, table->table[i].word, table->table[i].quantity, loadFactor);
		}
	}
	destroyTable(table, size);
	size = newsize;
	return newtable;
}