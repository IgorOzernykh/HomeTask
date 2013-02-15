#pragma once
#include "list.h"

struct HTable
{
	List **table;
	unsigned long long int size;
};

HTable *createHTable(unsigned long long int size);
void add (HTable *table, char *word, double &loadFactor);
void printTableAndStatistics(HTable *table, unsigned long long int tableSize, unsigned long long int quantityOfWords);
void destroyTable(HTable *table, unsigned long long int size);
HTable *rebuildTable (HTable *table, unsigned long long int &size, double &loadFactor);
