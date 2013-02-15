#pragma once

struct ListElement
{
	int arcWeight;
	int arcDirection;
	ListElement *next;
};

struct List
{
	ListElement *head;
	ListElement *tail;
	int *way;
	int verticeNumber;
	int mark;
	int size;
};

void addToList(List *list, int to, int length);
List *createList();
void destroyList(List *list);