#pragma once

struct ListElement
{
	int degree;
	int coeff;
	ListElement *next;
};

struct List
{
	ListElement *head;
	ListElement *tail;
	int size;
};

List *createList();
void addElementToPolynom(List *list, int degree, int coeff);
bool equals(List *list1, List* list2);
long long int value (List *list, int x);
void add (List *list1, List *list2, List *&list3);
void printPolynomial (List *list);
void destroyList(List *list);