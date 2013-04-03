#pragma once
#include <stdlib.h>

template <typename T>
class TreeNode
{
public:
    TreeNode(T itm) : LeftChild(NULL), RightChild(NULL), item(itm) {}
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

private:
    TreeNode *LeftChild;
    TreeNode *RightChild;
    T item;
};
