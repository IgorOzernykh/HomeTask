#include "OperandNode.h"

OperandNode::OperandNode(double val) :
    TreeNode(NULL, NULL),
    value(val)
{
}

double OperandNode::calc() throw(IncorrectExprExc)
{
    return value;
}

void OperandNode::print(ostream &output)
{
    output << value << " ";
}
