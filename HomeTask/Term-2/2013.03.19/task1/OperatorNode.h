#pragma once
#include "TreeNode.h"

/** OperatorNode class interface.
    Inherited from TreeNode
  */

class OperatorNode : public TreeNode
{
public:
    OperatorNode(char operat);
    void print(ostream& output);
    double calc() throw(IncorrectExprExc);
private:
    char operation;
};

