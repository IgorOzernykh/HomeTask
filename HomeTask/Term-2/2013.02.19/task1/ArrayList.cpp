#include "ArrayList.h"

ArrayList::ArrayList() :
    additionalSize(20),
    currentSize(20)
{
    array = new int[currentSize];
}

void ArrayList::swap (int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void ArrayList::checkOverFlow()
{
    const int eps = 2;
    if (currentSize - elementsCounter <= eps)
    {
        int *newarray = new int[currentSize + additionalSize];
        for (int i = 0; i < currentSize; i++)
        {
            newarray[i] = array[i];
        }
        int *toDel = array;
        array = newarray;
        delete []toDel;
        currentSize += additionalSize;
    }
    else
        return;
}

void ArrayList::add(int value) throw (string)
{
    for (int i = 0; i < elementsCounter; i++)
    {
        if (array[i] == value)
        {
            throw string("Value is already exist in ArrayList - ", value);
        }
    }
    checkOverFlow();
    array[elementsCounter] = value;
    elementsCounter++;
}

void ArrayList::remove(int value) throw (string)
{
    int index = -1;
    for (int i = 0; i < elementsCounter; i++)
    {
        if (array[i] == value)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        swap (array[index], array[elementsCounter - 1]);
        elementsCounter--;
    }
    else
        throw string("No value =", value);
}

void ArrayList::show() throw (string)
{
    if (elementsCounter != 0)
    {
        cout << "ArrayList: " << endl;
        for (int i = 0; i < elementsCounter; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    else
        throw string ("Nothing to show! ArrayList is empty!");
}

int &ArrayList::operator[](int index)
{
    if (index < 0)
        return array[0];
    if (index >= elementsCounter)
        return array[elementsCounter - 1];
    return array[index];
}

ArrayList::~ArrayList()
{
    currentSize = 0;
    elementsCounter = 0;
    delete []array;
}
