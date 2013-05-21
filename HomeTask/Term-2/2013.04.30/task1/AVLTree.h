#pragma once
#include "TreeNode.h"
#include "NothingToDelExc.h"
#include "EndOfSetExc.h"

/** AVL Tree template class.
    Has its iterator */


template <typename T>
class AVLTree
{
public:
    class AVLTreeIterator;

    AVLTree() : root(NULL), NodeCounter(0)
    {
    }
    ~AVLTree()
    {
        if (root != NULL)
            delete root;
    }
    /** Create new node if item doesn't exist, otherwise increases elemCounter */
    void add(T item)
    {
            addElement(root, item);
    }
    /** Remove Node if item exists */
    void removeNode(T item) throw (NothingToDelExc*)
    {
        if (root == NULL)
            throw new NothingToDelExc("Tree is empty!");
        if (!isExist(item))
            throw new NothingToDelExc("No such value!");
        removeNode(root, item);
    }
    /** Decreases elemCounter if it's > 1, otherwise remove node */
    void removeElement(T item)
    {
        if (root == NULL)
            throw new NothingToDelExc("Tree is empty!");
        if (!isExist(item))
            throw new NothingToDelExc("No such value!");
        removeElement(root, item);
    }
    bool isExist (T item)
    {
        return isExistElement (root, item);
    }
    int NodeCount()
    {
        return NodeCounter;
    }
    int TreeHeight()
    {
        return height(root);
    }
    TreeNode<T> *getRoot()
    {
        return root;
    }
private:
    TreeNode<T> *root;
    int height(TreeNode<T> *node);
    int balanceFactor(TreeNode<T> *node);
    void fixHeight(TreeNode<T> *node);
    void balanceNode(TreeNode<T> *&current);
    TreeNode<T> *RotateRight(TreeNode<T> *current);
    TreeNode<T> *RotateLeft(TreeNode<T> *current);
    void addElement(TreeNode<T> *&current, T item);
    void removeNode(TreeNode<T> *&current, T item);
    void removeElement(TreeNode<T> *&current, T item);
    bool isExistElement(TreeNode<T> *current, T item);
    bool isLeaf(TreeNode<T> *current);
    bool hasOneChild(TreeNode<T> *current);
    TreeNode<T> *LeftMostChild(TreeNode<T> *current);
    int NodeCounter;
};


template <typename T>
int AVLTree<T>::height(TreeNode<T> *node) //counts height of subtree
{
    return (node != NULL)? node->getHeight() : 0;
}

template <typename T>
int AVLTree<T>::balanceFactor(TreeNode<T> *node)
{
    return height(node->getRightChild()) - height(node->getLeftChild());
}

template <typename T>
void AVLTree<T>::fixHeight(TreeNode<T> *node) // fixes height if it has changed after rotation
{
    int HLeft = height(node->getLeftChild());
    int HRight = height(node->getRightChild());
    node->setHeight((HLeft > HRight ? HLeft : HRight) + 1);
}

template <typename T>
void AVLTree<T>::balanceNode(TreeNode<T> *&current) // makes small or big left/right rotation
{
    int BFactor = balanceFactor(current);
    if (BFactor >= -1 && BFactor <= 1)
    {
        return;
    }
    if (BFactor == 2)
    {
        if (balanceFactor(current->getRightChild()) >= 0)
        {
            current = RotateLeft(current);
        }
        else
        {
            current->setRightChild(RotateRight(current->getRightChild()));
            current = RotateLeft(current);
        }
    }
    else if (BFactor == -2)
    {
        if (balanceFactor(current->getLeftChild()) <= 0)
        {
            current = RotateRight(current);
        }
        else
        {
            current->setLeftChild(RotateLeft(current->getLeftChild()));
            current = RotateRight(current);
        }
    }
}

template <typename T>
TreeNode<T> *AVLTree<T>::RotateRight(TreeNode<T> *current)
{
    TreeNode<T> *pivot = current->getLeftChild();
    current->setLeftChild(pivot->getRightChild());
    pivot->setRightChild(current);
    fixHeight(current);
    fixHeight(pivot);
    return pivot;
}

template <typename T>
TreeNode<T> *AVLTree<T>::RotateLeft(TreeNode<T> *current)
{
    TreeNode<T> *pivot = current->getRightChild();
    current->setRightChild(pivot->getLeftChild());
    pivot->setLeftChild(current);
    fixHeight(current);
    fixHeight(pivot);
    return pivot;
}

template <typename T>
bool AVLTree<T>::isLeaf(TreeNode<T> *current)
{
    return current->getLeftChild() == NULL && current->getRightChild() == NULL;
}

template <typename T>
bool AVLTree<T>::hasOneChild(TreeNode<T> *current)
{
    return (current->getLeftChild() == NULL && current->getRightChild() != NULL)
            || (current->getRightChild() == NULL && current->getLeftChild() != NULL);
}

template <typename T>
TreeNode<T> *AVLTree<T>::LeftMostChild(TreeNode<T> *current)
{
    if (current->getLeftChild() != NULL)
    {
        return LeftMostChild(current->getLeftChild());
    }
    return current;
}

template <typename T>
bool AVLTree<T>::isExistElement(TreeNode<T> *current, T item)
{
    if (current != NULL)
    {
        if (current->getItem() == item)
        {
            return true;
        }
        else if (current->getItem() > item)
        {
            return isExistElement(current->getLeftChild(), item);
        }
        else
        {
            return isExistElement(current->getRightChild(), item);
        }
    }
    else
        return false;
}

template <typename T>
void AVLTree<T>::addElement(TreeNode<T> *&current, T item)
{
    if (current == NULL)
    {
        current = new TreeNode<T>(item);
        NodeCounter++;
    }
    else if (item < current->getItem())
        addElement(current->getLeftChild(), item);
    else if (item > current->getItem())
        addElement(current->getRightChild(), item);
    else
        current->setElemCounter(current->getElemCounter() + 1);
    fixHeight(current); // checks height of subtree and change it if it's necessary
    balanceNode(current); // balance subtree if balance factor >= 2
}

template <typename T>
void AVLTree<T>::removeNode(TreeNode<T> *&current, T item)
{
    if (item < current->getItem())
    {
        removeNode (current->getLeftChild(), item);
    }
    else if (item > current->getItem())
    {
        removeNode (current->getRightChild(), item);
    }
    else if (isLeaf(current))
    {
        delete current;
        current = NULL;
        NodeCounter--;
        return;
    }
    else if (hasOneChild(current))
    {
        if (current->getLeftChild() != NULL)
        {
            TreeNode<T> *temp = current->getLeftChild();
            current->setLeftChild(NULL);
            delete current;
            current = temp;
        }
        else if (current->getRightChild() != NULL)
        {
            TreeNode<T> *temp = current->getRightChild();
            current->setRightChild(NULL);
            delete current;
            current = temp;
        }
    }
    else
    {
        // replace item in ToRemoveNode (current) with item in its LeftMostChild, then deletes LMC
        // and checks balances of nodes between LMC and ToRemoveNode (current)
        TreeNode<T> *toReplace = LeftMostChild(current->getRightChild());
        current->setItem(toReplace->getItem());
        current->setElemCounter(toReplace->getElemCounter());
        removeNode(current->getRightChild(), toReplace->getItem());

    }
    NodeCounter--;
    fixHeight(current);
    balanceNode(current);
}

template <typename T>
void AVLTree<T>::removeElement(TreeNode<T> *&current, T item)
{
    if (item < current->getItem())
    {
        removeElement(current->getLeftChild(), item);
    }
    else if (item > current->getItem())
    {
        removeElement(current->getRightChild(), item);
    }
    else if (current->getElemCounter() > 1)
    {
        current->setElemCounter(current->getElemCounter() - 1);
    }
    else
    {
        removeNode(current, item);
    }
}

template <typename T>
class AVLTree<T>::AVLTreeIterator
{
public:
    AVLTreeIterator(AVLTree<T> *&tree) : tree(tree)
    {
        container = new QList<T>;
        parse(tree->getRoot());
        current = container->first();
        position = 0;
        size = container->size();
    }
    ~AVLTreeIterator()
    {
        delete container;
    }
    void add(T item)
    {
        tree->add(item);
        int index = container->indexOf(item);
        if (index >= 0)
        {
            container->insert(index, item);
        }
        else
        {
            container->append(item);
        }
        size++;
    }
    void remove()
    {
        T temp = current;
        if (hasNext())
        {
            current = container->at(position + 1);
        }
        tree->removeElement(temp);
        container->removeOne(temp);
        size--;
    }
    T next() throw (EndOfSetExc)
    {
        if (container->size() > 0)
        {
            if (position < size - 1)
            {
                T toReturn = current;
                current = container->at(++position);
                return toReturn;
            }
            else if (position == size - 1)
            {
                position++;
                return current;
            }
            else
            {
                throw EndOfSetExc();
            }
        }
        else
        {
            throw EndOfSetExc();
        }
    }
    bool hasNext()
    {
        return (position < container->size() - 1)? true : false;
    }

private:
    int position;
    int size;
    AVLTree<T> *tree;
    T current;
    QList<T> *container;
    void parse (TreeNode<T> *curr)
    {
        for (int i = 0; i < curr->getElemCounter(); i++)
        {
            container->append(curr->getItem());
        }
        if (curr->getLeftChild() != NULL)
        {
            parse(curr->getLeftChild());
        }
        if (curr->getRightChild() != NULL)
        {
            parse(curr->getRightChild());
        }
    }
};
