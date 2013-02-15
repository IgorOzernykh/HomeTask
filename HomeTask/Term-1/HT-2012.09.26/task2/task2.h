#pragma once
struct ListElement
{
	int value;
	ListElement *next;
};
struct List
{
	ListElement *head;
	ListElement *tail;
	int size;
};

List *createList();
bool isEmpty(List *list);
void add(List *list, int value);
List *fillList(int size);
void deleteElement(List *list, ListElement *del);
void delK(List* list, int k);