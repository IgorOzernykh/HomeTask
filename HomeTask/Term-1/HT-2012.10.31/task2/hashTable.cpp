#include "hashTable.h"
#include <string.h>
#include "list.h"
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

unsigned long long int key (unsigned long long int size, char *s)
{
	/*int len = strlen(array);
	unsigned long long int key = 0;
	unsigned long long int base = 1;
	const int alphabetSize = 26;
	for (int i = 0; i < len; i++)
	{
		key += ((array[i] - '0' ) * base) % (size);
		base *= alphabetSize;
	}
	return key % size;*/
	/*int len = strlen(s);
	int hash = 1;
	unsigned long long int base = 1;
	for (int i = 0; i < len; i++)
	{
		hash *= base;
		base *= s[i] - '0';
		hash %= size;
		hash = hash << 4;
		hash ^= s[i];
	}
	return hash % (size);*/
	/*int len = strlen(s);
	 const unsigned char *data = (const unsigned char *)(s);
	unsigned long long int crc = 216613626;
	  while ( len-- )
	   crc = ( crc * 16777619 ) ^ ( *data++ );
	 return crc % size;*/
	/*int len = strlen(s);
	unsigned long long int pow = 1;
	const int p = 1028201;
	unsigned long long int hash=0;
	for(int i = 0; i < len; i++)
	{
		hash+= s[i]*pow;
	    pow *= p;
	}
	return hash % size;*/
	/*unsigned long long int hash=(unsigned long long int )-1;
    while(*s) 
	{
        hash^=*s++;
        for(int n =0; n < 8; n++) 
			hash = (-(hash & 1)& 0xDB710641) ^ (hash >> 1);
    }
	return hash % size;*/
	int len = strlen(s);
	unsigned long long int pow = 1;
	const int p = 1028201;
	unsigned long long int hash=0;
	for(int i = 0; i < len; i++)
	{
		hash += s[i]*pow;
		hash ^= 0xD32DE03A;
		pow *= p;
	}
	return hash % size;
	/*const int base = 13;
	unsigned long long int factor = 1;
	unsigned long long int hash = 0;
	int i = 0;
	while (s[i] != '\0')
	{
		hash += int (s[i]) * factor;
		factor *= base;
		i++;
	}
	return hash % size;*/
	
}

void add (HTable *table, char *word, double &loadFactor)
{
	unsigned long long int pos = key (table->size, word);
	bool flag = addElement (table->table[pos], word);
	if (flag)
		loadFactor += (double(1) / table->size);

}

void printTableAndStatistics(HTable *table, unsigned long long int tableSize, unsigned long long int quantityOfWords)
{
	int collision = 0;
	int filled = 0;
	int empty = 0;
	for (unsigned long long int i = 0; i < tableSize; i++)
		if (table->table[i]->head != nullptr)
		{
			ListElement *tmp = table->table[i]->head;
			std::cout << tmp->array << " - " << tmp->quantity << "\n";
			filled++;
			while (tmp->next != nullptr)
			{
				collision++;
				tmp = tmp->next;
				std::cout << tmp->array << " - " << tmp->quantity << "\n";
			}
		}
		else 
			empty++;
	double loadFactor = double(filled) / tableSize;
	std::cout << "\nQuantity of collisions = " << collision << "\n"
			  << "Quantity of filled cells = " << filled << "\n"
			  << "Quantity of empty cells = " << empty << "\n"
			  << "Quantity of words = " << quantityOfWords << "\n"
			  << "Load factor = " << loadFactor << "\n";
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