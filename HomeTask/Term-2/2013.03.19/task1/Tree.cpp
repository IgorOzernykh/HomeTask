#include "Tree.h"

Tree::Tree() : root(NULL)
{
}


void Tree::parse(string inputname)
{
    ifstream input;
    input.open(inputname.c_str());
    parse(input, root);
    input.close();
}

bool isOperator(char sym)
{
    return (sym == '+' || sym == '-' || sym == '*' || sym == '/');
}

bool isNumber(char sym)
{
    return (sym >= '0' && sym <= '9');
}

void Tree::parse(ifstream &input, TreeNode *&currentNode)
{
    char sym = input.get();
    while (!input.eof() && !isNumber(sym) && !isOperator(sym))
    {
        sym = input.get();
    }
    if (isNumber(sym))
    {
        input.unget();
        int operand;
        input >> operand;
        currentNode = new OperandNode(operand);
    }
    else if (isOperator(sym))
    {
        currentNode = new OperatorNode(sym);
        parse(input, currentNode->getLeftChild());
        parse(input, currentNode->getRightChild());
    }

}

void Tree::print(string inputname)
{
    ofstream output;
    output.open(inputname.c_str());//, ios::app);
    if (root != NULL)
    {
        root->print(output);
    }
    output.close();
}

double Tree::calc()
{
    if (root != NULL)
    {
        return root->calc();
    }
    return 0;
}

Tree::~Tree()
{
    if (root != NULL)
        delete root;
}
