#include "list.h"
#include <string.h>

List *createList()
{
	List *temp = new List;
	temp->head = nullptr;
	temp->size = 0;
	return temp;
}

bool isEmpty(List *list)
{
	return list->size == 0;
}

void addWhenAlreadyExists (ListElement *tmp, ListElement *temp, bool &isAdded)
{
		tmp->quantity++;
		isAdded = true;
		delete [] temp->array;
		delete temp;
}

bool addElement(List *list, char *array)
{
	bool flag = false;
	ListElement *temp = new ListElement;
	temp->array = strdup(array);
	if (isEmpty(list))
	{
		list->head = temp;
		list->head->quantity = 1;
		list->head->next = nullptr;
		flag = true;
	}
	else
	{
		bool isAdded = false;
		ListElement *tmp = list->head;
		if (strcmp(tmp->array, temp->array) == 0)
		{
			addWhenAlreadyExists(tmp, temp, isAdded);
		}
		else while (!(isAdded) && tmp->next != nullptr)
		{
			tmp = tmp->next;
			if (strcmp(tmp->array, temp->array) == 0)
			{
				addWhenAlreadyExists(tmp, temp, isAdded);
			}
		}
		if (!(isAdded))
		{
			tmp->next = temp;
			tmp->next->quantity = 1;
			tmp->next->next = nullptr;
		}
	}
	list->size++;
	return flag;
}

void destroyList(List *list)
{
	ListElement *tmp = list->head;
	while (tmp->next != nullptr)
	{
		ListElement *toDelete = tmp;
		tmp = tmp->next;
		list->head = tmp;
		delete [] toDelete->array;
		delete toDelete;		
	}
	delete [] tmp->array;
	delete tmp;
}