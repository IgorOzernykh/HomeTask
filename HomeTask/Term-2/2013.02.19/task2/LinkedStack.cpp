#include "LinkedStack.h"

struct LinkedStack::StackElement
{
    int value;
    StackElement *next;
};

LinkedStack::LinkedStack()
{
    head = NULL;
}

LinkedStack::~LinkedStack()
{
    if (head != NULL)
    {
        while (head->next != NULL)
        {
            StackElement *toDel = head;
            head = head->next;
            delete toDel;
        }
        delete head;
    }
}

bool LinkedStack::isEmpty()
{
    return head == NULL;
}


void LinkedStack::push(int value)
{
    StackElement *temp = new StackElement;
    temp->value = value;
    if (isEmpty())
    {
        head = temp;
        head->next = NULL;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    elementsCounter++;
}

int LinkedStack::top()
{
    if (!isEmpty())
        return head->value;
    return 0;
}

int LinkedStack::pop()
{
    if (isEmpty())
        return 0;
    int value = top();
    StackElement *toDel = head;
    if (head->next != NULL)
    {
        head = head->next;
        delete toDel;
    }
    else
    {
        delete head;
        head = NULL;
    }
    elementsCounter--;
    return value;
}
