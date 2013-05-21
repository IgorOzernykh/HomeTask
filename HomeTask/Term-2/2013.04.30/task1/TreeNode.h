#pragma once
#include <QList>
#include <stdlib.h>

/** TreeNode template class */
template <typename T>
class TreeNode
{
public:
    TreeNode(T itm) : LeftChild(NULL), RightChild(NULL), item(itm), height(0), elemCounter(1) {}
    ~TreeNode()
    {
        if (LeftChild != NULL)
            delete LeftChild;
        if (RightChild != NULL)
            delete RightChild;
    }

    TreeNode *&getLeftChild()
    {
        return LeftChild;
    }
    TreeNode *&getRightChild()
    {
        return RightChild;
    }
    void setLeftChild(TreeNode *lChild)
    {
        LeftChild = lChild;
    }
    void setRightChild(TreeNode *rChild)
    {
        RightChild = rChild;
    }
    T getItem()
    {
        return item;
    }
    void setItem(T itm)
    {
        item = itm;
    }
    int getHeight()
    {
        return height;
    }
    void setHeight(int newHeight)
    {
        height = newHeight;
    }
    int getElemCounter()
    {
        return elemCounter;
    }
    void setElemCounter(int newElemCounter)
    {
        elemCounter = newElemCounter;
    }
private:
    TreeNode *LeftChild;
    TreeNode *RightChild;
    T item;
    int height;
    int elemCounter;
};
