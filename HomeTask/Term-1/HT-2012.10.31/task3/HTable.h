#pragma once

struct HTableElement
{
	int quantity;
	char *word;
};

struct HTable
{
	HTableElement *table;
	unsigned long long int size;
};



HTable *createHTable(unsigned long long int size);
void addHash1 (HTable *table, char *word, int quantity, double &loadFactor);
void addHash2 (HTable *table, char *word, int quantity, double &loadFactor, unsigned long long int index);
void printTableAndStatistics(HTable *table, unsigned long long int tableSize, unsigned long long int quantityOfWords);
void destroyTable(HTable *table, unsigned long long int size);
HTable *rebuildTable (HTable *table, unsigned long long int &size, double &loadFactor);
