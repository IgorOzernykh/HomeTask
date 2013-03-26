#include "PointerList.h"

struct PointerList::ListElement
{
    ListElement *next;
    ListElement *prev;
    int value;
};


PointerList::PointerList()
{
    head = NULL;
    tail = NULL;
}

bool PointerList::isExist(int value)
{
    if (head == NULL)
        return false;
    ListElement *temp = head;
    while (temp->next != NULL)
    {
        if (temp->value == value)
            return true;
        temp = temp->next;
    }
    if (temp->value == value)
        return true;
    return false;
}

void PointerList::add(int value) throw (string)
{
    if (!isExist(value))
    {
        ListElement *temp = new ListElement;
        temp->value = value;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = tail->next;
        }
        elementsCounter++;
    }
    else
        throw string("Value is already exist in PointerList - ", value);
}


void PointerList::remove(int value) throw (string)
{
    if (head == NULL)
    {
        cout << "Nothing to delete! PointerList is empty!" << endl;
        return;
    }
    else
    {
        ListElement *tmp = head;
        int i = 0;
        bool wasDeleted = false;
        while (i < elementsCounter)
        {
            if (tmp->value == value)
            {
                if (head == tail)
                {
                    delete tmp;
                    head = NULL;
                    tail = NULL;
                    elementsCounter--;
                }
                else
                {
                    ListElement *toDel = tmp;
                    if (tmp == head)
                    {
                        head = head->next;
                        head->prev = NULL;
                        tmp = head;
                    }
                    else if (tmp == tail)
                    {
                        tail = tmp->prev;
                        tail->next = NULL;
                    }
                    else
                    {
                        tmp->prev->next = tmp->next;
                        tmp->next->prev = tmp->prev;
                        tmp = tmp->next;
                    }
                    delete toDel;
                    elementsCounter--;
                }
                return;
            }
            else if (i < elementsCounter - 1)
                tmp = tmp->next;
            i++;
        }
        if (!wasDeleted)
        {
            throw string("No value = ", value);
        }
    }
}

void PointerList::show() throw (string)
{
    if (head == NULL)
    {
        throw string("Nothing to show! PointerList is empty!");
    }
    else
    {
        cout << "PointerList: " << endl;
        ListElement *temp = head;
        while (temp->next != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << temp->value << endl;
    }
}

int& PointerList::operator[](int index)
{
    if (index <= 0)
        return head->value;
    if (index >= elementsCounter)
        return tail->value;
    ListElement *temp = head;
    for (int i = 0; i < index; i++)
        temp = temp->next;
    return temp->value;
}

PointerList::~PointerList()
{
    while (elementsCounter > 1)
    {
        ListElement *toDel = head;
        head = head->next;
        head->prev = NULL;
        delete toDel;
        elementsCounter--;
    }
    delete head;
}
