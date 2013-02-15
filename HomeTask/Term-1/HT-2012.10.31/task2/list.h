#pragma once

struct ListElement
{
	char *array;
	int quantity;
	ListElement *next;
};

struct List
{
	ListElement *head;
	int size;
};
bool addElement (List *list, char *array);
void destroyList (List *list);
List *createList();

