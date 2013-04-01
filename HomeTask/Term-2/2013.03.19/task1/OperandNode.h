#pragma once
#include "TreeNode.h"

/** OperandNode class interface.
    Inherited from TreeNode.
  */

class OperandNode : public TreeNode
{
public:
    OperandNode(double val);
    void print(ostream& output);
    double calc() throw(IncorrectExprExc);
private:
    double value;
};

