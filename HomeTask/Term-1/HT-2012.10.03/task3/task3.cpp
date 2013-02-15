#include "task3.h"
#include <iostream>
using std::cout;
using std::cin;
List *createList()
{
	List *temp = new List;
	temp->head = NULL;
	temp->size = 0;
	return temp;
}
bool isEmpty(List *list)
{
	return list->size == 0;
}
void add (List *list, int value)
{
	ListElement *temp = new ListElement;
	temp->value = value;
	if (isEmpty(list))
	{
		list->head = temp;
		temp->next = list->head;
		temp->prev = list->head;
	}
	else
	{
		bool flag = true;
		ListElement *tmp = list->head;
		for (int i = 1; i <= list->size; i++)
		{
			if (value <= tmp->value)
			{
				temp->next = tmp;
				tmp->prev->next = temp;
				temp->prev = tmp->prev;
				tmp->prev = temp;
				if (list->head == tmp)
					list->head = temp;
				flag = false;
				break;
			}
			tmp = tmp->next;
		}
		if (flag)
		{
			temp->next = list->head;
			temp->prev = list->head->prev;
			list->head->prev->next = temp;
			list->head->prev = temp;
		}
	}
	list->size++;
}
void deleteValue(List *list, int value)
{
	ListElement *tmp = list->head;
	if (!isEmpty(list))
	{
		bool flag;
		bool flag2 = true;
		int i = 1;
		while (i <= list->size)
		{
			flag = true;
			if (tmp == list->head && list->size == 1 && tmp->value == value)
			{
				delete list->head;
				list->size--;
				flag = false;
				flag2 = false;
			}
			else if (tmp->value == value)
			{
				ListElement *del = tmp;
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				list->size--;
				if (tmp == list->head)
					list->head = tmp->next;
				tmp = tmp->next; 
				delete del;
				flag = false;
				flag2 = false;
			}
			if (flag)
			{
				i++;
				tmp = tmp->next;
			}
		}
		if (flag2)
			cout << "\nNo such value\n\n";
	}
	else
		cout << "\nList is empty\n\n";
}
void printList(List *list)
{
	cout << "\n";
	ListElement *tmp = list->head;
	if (!isEmpty(list))
	{
		cout << "List:\n";
		for (int i = 1; i <= list->size; i++)
		{
			cout << "   " << tmp->value << "\n";
			tmp = tmp->next;
		}
	}
	else
	{
		cout << "List is empty\n";
	}
	cout << "\n";
}
void deleteList(List* list)
{
	while (!isEmpty(list))
	{
		ListElement *tmp = list->head;
		ListElement *del = tmp;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		list->size--;
		if (tmp == list->head)
			list->head = tmp->next;
		tmp = tmp->next; 
		delete del;
	}
}