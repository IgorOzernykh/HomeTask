#include "OperatorNode.h"

OperatorNode::OperatorNode(char operat) :
    TreeNode(NULL, NULL),
    operation(operat)
{
}

double OperatorNode::calc() throw(IncorrectExprExc)
{
    double leftResult = this->leftChild->calc();
    double rightResult = this->rightChild->calc();
    double result;
    switch (operation)
    {
    case '+':
        result = leftResult + rightResult;
        break;
    case '-':
        result = leftResult - rightResult;
        break;
    case '*':
        result = leftResult * rightResult;
        break;
    case '/':
        if (rightResult != 0)
        {
            result = leftResult / rightResult;
            break;
        }
        else throw IncorrectExprExc("Division by zero!");
    }
    return result;
}

void OperatorNode::print(ostream &output)
{
    leftChild->print(output);
    rightChild->print(output);
    output << operation << " ";
}

