#pragma once
#include <stdlib.h>
#include "List.h"

class PointerList : public List
{
public:

    void add(int value) throw (string);
    void remove(int value) throw (string);
    void show() throw (string);
    virtual int &operator[](int index);
    PointerList();
    ~PointerList();
private:
    struct ListElement;
    bool isExist(int value);
    ListElement *head;
    ListElement *tail;
};

