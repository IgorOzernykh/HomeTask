#include "task2.h"
#include <iostream>

List *createList()
{
	List *temp = new List;
	temp->head = NULL;
	temp->tail = NULL;
	temp->size = 0;
	return temp;
}

bool isEmpty(List *list)
{
	return list->head == NULL;
}

void add (List *list, int value)
{
	ListElement *temp = new ListElement;
	temp->value = value;
	if (isEmpty(list))
	{
		list->head = temp;
		list->tail = temp;
		temp->next = list->head;
	}
	else
	{
		list->tail->next = temp;
		list->tail = temp;
		temp->next = list->head;
	}
	list->size++;
}

List *fillList(int size)
{
	List *list = createList();
	for (int i = 1; i <= size; i++)
	{
		add(list, i);
	}
	return list;
}

void delK(List* list, int k)
{
	ListElement *tmp = list->head;
	ListElement *start = tmp;
	while (list->size != 1)
	{
		for (int i = 1; i < k; i++)
			tmp = tmp->next;
		start = tmp->next;
		deleteElement(list, tmp);
		tmp = start;
	}
}

void deleteElement(List *list, ListElement *del)
{
	if (!isEmpty(list))
	{
		if (list->size == 1)
		{
			list->head = NULL;
			list->tail = NULL;
			delete del;
		}
		else if (del == list->tail)
		{
			ListElement *tmp = list->head;
			while (tmp->next != list->tail)
				tmp = tmp->next;
			tmp->next = list->head;
			delete del;
			list->tail = tmp;
		}
		else if(del == list->head)
		{
			list->tail->next = del->next;
			list->head = list->head->next;
			delete del;
		}
		else
		{
			ListElement *tmp = list->head;
			while (tmp->next != del)
				tmp = tmp->next;
			tmp->next = del->next;
			delete del;
		}
	}
	list->size--;
}