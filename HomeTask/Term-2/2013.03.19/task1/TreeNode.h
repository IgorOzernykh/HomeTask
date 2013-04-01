#pragma once
#include "IncorrectExprExc.h"
#include <stdlib.h>
#include <fstream>
using namespace std;

/** TreeNode class interface.
  You can inherit other Node classes (e.g. operandNode, operatorNode for Parse Tree)
  */

class TreeNode
{
public:
    TreeNode(TreeNode *lChild, TreeNode *rChild) : leftChild(lChild), rightChild(rChild) {}
    ~TreeNode()
    {
        if (leftChild != NULL)
            delete leftChild;
        if (rightChild != NULL);
            delete rightChild;
    }
    /** Function prints contained object to the file */
    virtual void print(ostream& output) = 0;
    virtual double calc() throw(IncorrectExprExc) = 0;
    TreeNode *&getLeftChild()
    {
        return leftChild;
    }
    TreeNode *&getRightChild()
    {
        return rightChild;
    }
    void setLeftChild(TreeNode *lchild)
    {
        leftChild = lchild;
    }
    void setRightChild(TreeNode *rchild)
    {
        rightChild = rchild;
    }

protected:
    TreeNode *leftChild;
    TreeNode *rightChild;
};


