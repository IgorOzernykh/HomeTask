#pragma once
#include <stdlib.h>
#include "List.h"

class PointerList : public List
{
public:

    void add(int value);
    void remove(int value);
    void show();
    PointerList();
	~PointerList();
private:
    struct ListElement;

    bool isExist(int value);
    ListElement *head;
    ListElement *tail;
};

