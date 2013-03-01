#include "ArrayStack.h"

ArrayStack::ArrayStack() :
    additionalSize(20),
    currentSize(20)
{
    array = new int[currentSize];
}

ArrayStack::~ArrayStack()
{
    delete []array;
}

bool ArrayStack::isEmpty()
{
    return elementsCounter == 0;
}

int ArrayStack::top()
{
    if (elementsCounter > 0)
        return array[elementsCounter - 1];
    return 0;
}

int ArrayStack::pop()
{
    int value = top();
    elementsCounter--;
    return value;
}

void ArrayStack::checkOverFlow()
{
    const int eps = 3;
    if (currentSize - elementsCounter <= eps)
    {
        int *newArray = new int[currentSize + additionalSize];
        for (int i = 0; i < elementsCounter; i++)
        {
            newArray[i] = array[i];

        }
        int *toDel = array;
        array = newArray;
        delete []toDel;
        currentSize += additionalSize;
    }
    else
        return;
}

void ArrayStack::push(int value)
{
    checkOverFlow();
    array[elementsCounter++] = value;
}
