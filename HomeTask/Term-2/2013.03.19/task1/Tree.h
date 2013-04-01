#pragma once

#include "OperandNode.h"
#include "OperatorNode.h"

/** Parse Tree class interface
  */

class Tree
{
public:
    Tree();
    ~Tree();
    /** Function fills the Tree with the integer values and operation */
    void parse(string filename);
    /** Function prints math expression contained in the tree to the file */
    void print(string filename);
    /** Function calculates math expression in the tree */
    double calc();
private:
    void parse(ifstream& input, TreeNode *&currentNode);
    TreeNode *root;
};

