#include "list.h"

List *createList()
{
	List *temp = new List;
	temp->head = nullptr;
	temp->tail = nullptr;
	temp->size = 0;
	return temp;
}

void addToList(List *list, int to, int length)
{
	ListElement *temp = new ListElement;
	temp->arcDirection = to;
	temp->arcWeight = length;
	if (list->head == nullptr)
	{
		list->head = temp;
		list->tail = temp;
		list->head->next = nullptr;
	}
	else 
	{
		list->tail->next = temp;
		list->tail = list->tail->next;
		list->tail->next = nullptr;
	}
	list->size++;
}
void destroyList(List *list)
{
	while (list->head != list->tail)

	{
		ListElement *toDelete = list->head;
		list->head = list->head->next;
		delete toDelete;
	}
	delete list->head;
	delete []list->way;
}