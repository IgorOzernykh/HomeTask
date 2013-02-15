#include <stdlib.h>
#include "6-2.h"
#include <iostream>

using std::cout;

Tree *createTree()
{
    Tree *tree = new Tree;
    tree->root = NULL;
    return tree;
}

TreeNode *createNodeSymbol(char symbol)
{
    TreeNode *node = new TreeNode;
    node->symbol = symbol;
	node->value = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode *createNodeValue(int value)
{
    TreeNode *node = new TreeNode;
    node->value = value;
	node->symbol = 'x';
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool isLeaf(TreeNode *node)
{
    return (node->left == NULL && node->right == NULL);
}

void addValue(TreeNode *&node, int value, bool &flag)
{
	if (node == NULL)
    {
		flag = true;
        node = createNodeValue(value);
        return;
    }
	else
	{
		if (node->symbol != 'x')
			addValue (node->left, value, flag);
		else return;
		if (node->symbol != 'x')
		{
			if (!flag)
				addValue (node->right, value, flag);
		}
		else return;
	}
}

void addValue(Tree *tree, int value)
{
	bool flag = false;
    addValue(tree->root, value, flag);
}

void addSymbol(TreeNode *&node, char symbol, bool &flag)
{
    if (node == NULL)
    {
		flag = true;
        node = createNodeSymbol(symbol);
        return;
    }
	else
	{
		if (node->symbol != 'x')
			addSymbol (node->left, symbol, flag);
		else return;
		if (node->symbol != 'x')
		{
			if (!flag)
				addSymbol (node->right, symbol, flag);
		}
		else return;
	}
}

void addSymbol(Tree *tree, char symbol)
{
	bool flag = false;
    addSymbol(tree->root, symbol, flag);
}

void result (TreeNode *node)
{
	while (!isLeaf(node))
		if (isLeaf(node->left) && isLeaf(node->right))
		{
			int tmp1 = node->left->value;
			int tmp2 = node->right->value;
			switch (node->symbol)
			{
			case '+':
				node->value = tmp1 + tmp2;
				break;
			case '-':
				node->value = tmp1 - tmp2;
				break;
			case '*':
				node->value = tmp1 * tmp2;
				break;
			case '/':
				node->value = tmp1 / tmp2;
			}
			node->symbol = 'x';
			delete node->left;
			node->left = NULL;
			delete node->right;
			node->right = NULL;
		}
		else 
		{
			result(node->left);
			result(node->right);
		}
}

int result (Tree *tree)
{
	result(tree->root);
	return tree->root->value;
}

void print (TreeNode *node)
{
	if (node->left != NULL && node->right != NULL)
	{
		print (node->left);
		
		print (node->right);
		std::cout << node->symbol << " ";
	}
	else 
	{
		std::cout << node->value << " ";
		if (node->right != NULL)
			print (node->right);		
	}
}

void print (Tree *tree)
{
	if (tree->root != NULL)
		print (tree->root);
	else std::cout << "\nSet is empty\n\n";
}
