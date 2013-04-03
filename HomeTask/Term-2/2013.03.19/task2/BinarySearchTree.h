#pragma once
#include "TreeNode.h"
#include "AlreadyExistExc.h"
#include "NothingToDelExc.h"

/** BinarySearchTree template class.
    Has add, remove and search external functions */

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree() : root(NULL), ElemCounter(0) {}
    ~BinarySearchTree()
    {
        if (root != NULL)
            delete root;
    }
    bool isExistInTree (T item)
    {
        return isExistElement (root, item);
    }

    void add(T item) throw (AlreadyExistExc)
    {
            addElement(root, item);
    }

    void remove(T item) throw (NothingToDelExc*)
    {
        if (root == NULL)
            throw new NothingToDelExc("Tree is empty!");
        if (!isExistInTree(item))
            throw new NothingToDelExc("No such value!");
        removeElement(root, item);
        ElemCounter--;
    }
    TreeNode<T> *getRoot()
    {
        return root;
    }

private:
    /** Recursive Functions that all necessary work in the tree */
    bool isExistElement(TreeNode<T> *currentNode, T item);
    void addElement(TreeNode<T> *&currentNode, T item) throw (AlreadyExistExc);
    void removeElement(TreeNode<T> *&currentNode, T item);
    /** 3 Fuctions for removing elements */
    bool isLeaf(TreeNode<T> *currentNode);
    bool hasOneChild(TreeNode<T> *currentNode);
    TreeNode<T> *LeftMostChild(TreeNode<T> *currentNode);
    TreeNode<T> *root;
    unsigned int ElemCounter;
};

template <typename T>
bool BinarySearchTree<T>::isLeaf(TreeNode<T> *currentNode)
{
    return currentNode->getLeftChild() == NULL && currentNode->getRightChild() == NULL;
}

template <typename T>
bool BinarySearchTree<T>::hasOneChild(TreeNode<T> *currentNode)
{
    return (currentNode->getLeftChild() == NULL && currentNode->getRightChild() != NULL)
            || (currentNode->getRightChild() == NULL && currentNode->getLeftChild() != NULL);
}

template <typename T>
TreeNode<T> *BinarySearchTree<T>::LeftMostChild(TreeNode<T> *currentNode)
{
    if (currentNode->getLeftChild() != NULL)
    {
        return LeftMostChild(currentNode->getLeftChild());
    }
    return currentNode;
}

template <typename T>
bool BinarySearchTree<T>::isExistElement(TreeNode<T> *currentNode, T item)
{
    if (currentNode != NULL)
    {
        if (currentNode->getItem() == item)
        {
            return true;
        }
        else if (currentNode->getItem() > item)
        {
            return isExistElement(currentNode->getLeftChild(), item);
        }
        else
        {
            return isExistElement(currentNode->getRightChild(), item);
        }
    }
    else
        return false;
}

template <typename T>
void BinarySearchTree<T>::addElement(TreeNode<T> *&currentNode, T item) throw (AlreadyExistExc)
{
    if (currentNode == NULL)
    {
        currentNode = new TreeNode<T>(item);
        ElemCounter++;
        return;
    }
    if (item < currentNode->getItem())
        addElement(currentNode->getLeftChild(), item);
    else if (item > currentNode->getItem())
        addElement(currentNode->getRightChild(), item);
    else
        throw AlreadyExistExc();
}

template <typename T>
void BinarySearchTree<T>::removeElement(TreeNode<T> *&currentNode, T item)
{
    if (item < currentNode->getItem())
        removeElement (currentNode->getLeftChild(), item);
    else if (item > currentNode->getItem())
        removeElement (currentNode->getRightChild(), item);
    else if (isLeaf(currentNode))
    {
        delete currentNode;
        currentNode = NULL;
    }
    else if (hasOneChild(currentNode))
    {
        if (currentNode->getLeftChild() != NULL)
        {
            TreeNode<T> *temp = currentNode->getLeftChild();
            delete currentNode;
            currentNode = temp;
        }
        else if (currentNode->getRightChild() != NULL)
        {
            TreeNode<T> *temp = currentNode->getRightChild();
            delete currentNode;
            currentNode = temp;
        }
    }
    else
    {
        TreeNode<T> *toReplace = LeftMostChild(currentNode->getRightChild());
        currentNode->setItem(toReplace->getItem());
        removeElement(toReplace, toReplace->getItem());
    }
}
