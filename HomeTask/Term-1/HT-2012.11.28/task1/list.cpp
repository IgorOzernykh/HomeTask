#include "list.h"
#include <iostream>

using std::cout;
using std::cin;

List *createList()
{
	List *temp = new List;
	temp->head = nullptr;
	temp->tail = nullptr;
	temp->size = 0;
	return temp;
}

void addElementToPolynom(List *list, int degree, int coeff)
{
	ListElement *temp = new ListElement;
	temp->degree = degree;
	temp->coeff = coeff;
	if (list->head == nullptr)
	{
		list->head = temp;
		list->tail = temp;
		list->head->next = nullptr;
		list->tail->next = nullptr;
	}
	else
	{
		list->tail->next = temp;
		list->tail = list->tail->next;
		list->tail->next = nullptr;
	}
}

bool equalElements (int degree1, int degree2, int coeff1, int coeff2)
{
	if (degree1 == degree2 && coeff1 == coeff2)
		return true;
	else
		return false;
}

bool equals(List *list1, List* list2)
{
	if (list1->size != list2->size || list1->size == 0)
	{
		return false;
	}
	else
	{
		ListElement *temp1 = list1->head;
		ListElement *temp2 = list2->head;
		bool areEqual = true;
		while (temp1->next != nullptr && areEqual)
		{
			areEqual = equalElements (temp1->degree, temp2->degree, temp1->coeff, temp2->coeff);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		if (areEqual)
		{
			areEqual = equalElements (temp1->degree, temp2->degree, temp1->coeff, temp2->coeff);
			return areEqual;
		}
		else
			return false;
	}
}



long long int elementValue (int degree, int coeff, int x)
{
	long long int elementValue = 1;
	for (int i = 0; i < degree; i++)
	{
		elementValue *= x;
	}
	elementValue *= coeff;
	return elementValue;
}

long long int value (List *list, int x)
{
	if (list->head != nullptr)
	{
		ListElement *tmp = list->head;
		long long int value = 0;
		while (tmp->next != nullptr)
		{
			long long int elementResult = elementValue (tmp->degree, tmp->coeff, x);
			value += elementResult;
			tmp = tmp->next;
		}
		long long int elementResult = elementValue (tmp->degree, tmp->coeff, x);
		value += elementResult;
		return value;
	}
	else 
		return 0;
}



void add (List *list1, List *list2, List *&list3)
{
	if (list1->head != nullptr && list2->head != nullptr)
	{
		ListElement *tmp1 = list1->head;
		ListElement *tmp2 = list2->head;
		if (list1->size > list2->size)
		{
			while (tmp1->degree != tmp2->degree)
			{
				addElementToPolynom(list3, tmp1->degree, tmp1->coeff);
				tmp1 = tmp1->next;
			}
			list3->size = list1->size;
		}
		else if (list1->size < list2->size)
		{
			while (tmp1->degree != tmp2->degree)
			{
				addElementToPolynom(list3, tmp2->degree, tmp2->coeff);
				tmp2 = tmp2->next;
			}
			list3->size = list2->size;
		}
		while (tmp1 != list1->tail)
		{
			addElementToPolynom(list3, tmp1->degree, tmp1->coeff + tmp2->coeff);
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		addElementToPolynom(list3, tmp1->degree, tmp1->coeff + tmp2->coeff);
	}
}

void destroyList(List *list)
{
	ListElement *tmp = list->head;
	while (tmp->next != nullptr)
	{
		ListElement *toDelete = tmp;
		tmp = tmp->next;
		list->head = tmp;
		delete toDelete;		
	}
	delete tmp;
	delete list;
}

void printPolynomial (List *list)
{
	ListElement *tmp = list->head;
	while (tmp->coeff == 0)
	{
		tmp = tmp->next;
	}
	if (tmp->degree != 1)
	{
		if (tmp->coeff == 1)
		{
			cout << "x^" << tmp->degree;
		}
		else if (tmp->coeff == -1)
		{
			cout << "-x^" << tmp->degree;
		}
		else cout << tmp->coeff << "x^" << tmp->degree;
	}
	else 
	{
		if (tmp->coeff == 1)
		{
			cout << "x";
		}
		else if (tmp->coeff == -1)
		{
			cout << "-x";
		}
		else cout << tmp->coeff << "x";
	}
	tmp = tmp->next;
	while (tmp != list->tail)
	{
		if (tmp->degree > 1)
		{
			if (tmp->coeff != 0)
			{
				if (tmp->coeff > 0)
				{
					if (tmp->coeff != 1)
						cout << "+" << tmp->coeff << "x^" << tmp->degree;
					else cout << "+" << "x^" << tmp->degree;
				}
				else if (tmp->coeff != -1)
					cout << tmp->coeff << "x^" << tmp->degree;
				else cout << "-x^" << tmp->degree;
			}
		}
		else if (tmp->coeff != 0)
		{
			if (tmp->coeff > 0)
			{
				if (tmp->coeff != 1)
					cout << "+" << tmp->coeff << "x";
				else cout << "+" << "x";
			}
			else if (tmp->coeff != -1)
				cout << tmp->coeff << "x";
			else cout << "-x";
		}
		tmp = tmp->next;
	}
	if (tmp->coeff > 0)
		cout << "+" << tmp->coeff;
	else if (tmp->coeff < 0)
		cout << tmp->coeff;
}