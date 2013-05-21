#pragma once
#include "AVLTree.h"

/** Bag te,plate class.
    Works with AVLTree and allows to add, remove and search elements.
    Has its iterator */

template <typename T>
class Bag
{
public:
    class Iterator;
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

template <typename T>
class Bag<T>::Iterator
{
public:
    Iterator(Bag<T> *bag) : iterator(bag->tree) {}
    void add(T item)
    {
        iterator.add(item);
    }
    void remove()
    {
        iterator.remove();
    }
    T next()
    {
        return current = iterator.next();
    }
    bool hasNext()
    {
        return iterator.hasNext();
    }

private:
    typename AVLTree<T>::AVLTreeIterator iterator;
    AVLTree<T> *tree;
    T current;
};
