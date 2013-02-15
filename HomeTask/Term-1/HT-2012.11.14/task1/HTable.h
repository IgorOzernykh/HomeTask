#pragma once
#include "List.h"

struct HTable
{
	List **table;
	unsigned long long int size;
};

HTable *createHTable(unsigned long long int size);
void add (HTable *table, char *word, double &loadFactor);
void destroyTable(HTable *table, unsigned long long int size);
HTable *rebuildTable (HTable *table, unsigned long long int &size, double &loadFactor);
bool isInTable (HTable *table, unsigned long long int size, char *word);