#pragma once
#include "AVLTree.h"

/** Bag te,plate class.
    Works with AVLTree and allows to add, remove and search elements */

template <typename T>
class Bag
{
public:
    Bag()
    {
        tree = new AVLTree<T>;
    }
    ~Bag()
    {
        delete tree;
    }
    void add(T item)
    {
        tree->add(item);
    }
    void removeOneElement(T item)
    {
        tree->removeElement(item);
    }
    void removeAllElements(T item)
    {
        tree->removeNode(item);
    }
    bool search(T item)
    {
        return tree->isExist(item);
    }
    int Counter()
    {
        return tree->NodeCount();
    }

private:
    AVLTree<T> *tree;
};
