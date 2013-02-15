#include "HTable.h"
#include <string.h>
#include "List.h"
#include <iostream>
#include <limits.h>

HTable *createHTable(unsigned long long int size)
{
	HTable *temp = new HTable;
	List **table = new List *[size];
	for (unsigned long long int i = 0; i < size; i++)
	{
		table[i] = createList();
	}
	temp->size = size;
	temp->table = table;
	return temp;
}

unsigned long long int hash (unsigned long long int size, char *array)
{
	int len = strlen(array);
	unsigned long long int hash = 0;
	unsigned long long int base = 1;
	const int alphabetSize = 26;
	for (int i = 0; i < len; i++)
	{
		hash += ((array[i] - '0') * base) % (size);
		base *= alphabetSize;
	}
	return hash % size;
}

void add (HTable *table, char *word, double &loadFactor)
{
	unsigned long long int pos = hash (table->size, word);
	bool flag = addElement (table->table[pos], word);
	if (flag)
		loadFactor += (double(1) / table->size);

}

void destroyTable(HTable *table, unsigned long long int size)
{
	for (unsigned long long int i = 0; i < size; i++)
	{
		if (table->table[i]->head != nullptr)
			destroyList(table->table[i]);
		delete table->table[i];
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
		if (table->table[i]->head != nullptr)
		{
			ListElement *tmp = table->table[i]->head;
			add(newtable, tmp->array, loadFactor);
			while (tmp->next != nullptr)
			{
				tmp = tmp->next;
				add(newtable, tmp->array, loadFactor);
			}
		}
	}
	destroyTable(table, size);
	size = newsize;
	return newtable;
}

bool isInTable (HTable *table, unsigned long long int size, char *str)
{
	unsigned long long int pos = hash (size, str);
	ListElement *tmp = table->table[pos]->head;
	if (tmp != nullptr)
	{
		while (tmp->next != nullptr)
		{
			if (strcmp(tmp->array, str) == 0)
			{
				return true;
			}
			else tmp = tmp->next;
		}
		return strcmp(tmp->array, str) == 0;
	}
	else 
		return false;
}