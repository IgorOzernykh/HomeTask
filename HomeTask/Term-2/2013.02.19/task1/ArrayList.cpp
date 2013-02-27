#include "ArrayList.h"
#include <iostream>
using namespace std;

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

void ArrayList::add(int value)
{
    for (int i = 0; i < elementsCounter; i++)
    {
        if (array[i] == value)
        {
            cout << "Value " << value << " in ArrayList is already exist!" << endl;
            return;
        }
    }
    checkOverFlow();
    array[elementsCounter] = value;
    elementsCounter++;
}

void ArrayList::remove(int value)
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
        cout << "No value = " << value << "!" << endl;
}

void ArrayList::show()
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
        cout << "Nothing to show! ArrayList is empty!" << endl;
}

ArrayList::~ArrayList()
{
	currentSize = 0;
    elementsCounter = 0;
    delete []array;
}
