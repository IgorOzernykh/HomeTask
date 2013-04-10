#pragma once
#include "BinarySearchTree.h"

/** Set template class based on BinarySearchTree.
    Can merge or intersect two sets. */

template <typename T>
class Set
{
public:
    Set()
    {
        tree = new BinarySearchTree<T>();
    }
    ~Set()
    {
        delete tree;
    }
    void add(T item)
    {
        tree->add(item);
    }
    void remove(T item)
    {
        tree->remove(item);
    }
    bool exists(T item)
    {
        return tree->isExist(item);
    }
    Set<T> *intersect(const Set *anotherSet);
    Set<T> *merge(const Set *anotherSet);

private:
    void traverseForMerger(TreeNode<T> *current, Set<T> *result);
    void traverseForIntersection(TreeNode<T> *current, Set<T> *result);
    BinarySearchTree<T> *tree;
};

template <typename T>
void Set<T>::traverseForMerger(TreeNode<T> *current, Set<T> *result)
{
    if (current != NULL)
    {
        traverseForMerger(current->getLeftChild(), result);
        try
        {
            result->add(current->getItem());
        }
        catch (std::exception)
        {}
        traverseForMerger(current->getRightChild(), result);
    }
}

template <typename T>
void Set<T>::traverseForIntersection(TreeNode<T> *current, Set<T> *result)
{
    if (current != NULL)
    {
        traverseForIntersection(current->getLeftChild(), result);
        if (tree->isExist(current->getItem()))
        {
            try
            {
                result->add(current->getItem());
            }
            catch(std::exception)
            {}
        }
        traverseForIntersection(current->getRightChild(), result);
    }
}

template <typename T>
Set<T> *Set<T>::merge(const Set *anotherSet)
{
    Set<T> *result = new Set<T>();
    traverseForMerger(anotherSet->tree->getRoot(), result);
    traverseForMerger(tree->getRoot(), result);
    return result;
}

template <typename T>
Set<T> *Set<T>::intersect(const Set *anotherSet)
{
    Set<T> *result = new Set<T>();
    traverseForIntersection(anotherSet->tree->getRoot(), result);
    return result;
}
