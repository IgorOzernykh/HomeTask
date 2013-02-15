#include <stdlib.h>
#include "bst.h"
#include <iostream>
using std::cout;
Tree *createTree()
{
    Tree *tree = new Tree;
    tree->root = NULL;
    return tree;
}
bool exists(TreeNode *root, int value)
{
    if (root == NULL)
        return false;
    if (root->value == value)
        return true;
	if (root->value > value)
        return exists(root->left, value);
    else if (root->value < value)
        return exists(root->right, value);
}
bool exists(Tree *tree, int value)
{
    return exists(tree->root, value);
}
TreeNode *createNode(int value)
{
    TreeNode *node = new TreeNode;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void add(TreeNode *&node, int value)
{
    if (node == NULL)
    {
        node = createNode(value);
        return;
    }

    if (value < node->value)
        add(node->left, value);
    else
        add(node->right, value);
}
void add(Tree *tree, int value)
{
    add(tree->root, value);
}
TreeNode *leftmostChild(TreeNode *node)
{
    if (node->left != NULL)
        return leftmostChild(node->left);
    else
        return node;
}
TreeNode *prevLeftmostChild(TreeNode *node)
{
	if (node->left != NULL)
	    if (node->left->left != NULL)
		    return prevLeftmostChild(node->left);
		else
			return node;
	else
		return node;
}
TreeNode *rightmostChild(TreeNode *node)
{
    if (node->right != NULL)
        return rightmostChild(node->right);
    else
        return node;
}
TreeNode *prevRightmostChild(TreeNode *node)
{
	if (node->right != NULL)
		if (node->right->right != NULL)
			return prevRightmostChild(node->right);
		else
			return node;
	else 
		return node;
}

bool isLeaf(TreeNode *node)
{
    return (node->left == NULL && node->right == NULL);
}
bool hasOneChild(TreeNode *node)
{
    return ((node->left != NULL && node->right == NULL)
            || (node->left == NULL && node->right != NULL));
}
void remove(TreeNode *&node, int value, char direction)
{
   if (value < node->value)
	   remove (node->left, value, direction);
   else if (value > node->value)
	   remove (node->right, value, direction);
   else if (isLeaf(node))
   {
	   delete node;
	   node = NULL;
   }
   else if (hasOneChild(node))
   {
	   if (node->left != NULL)
	   {
		   TreeNode *temp = node->left;
		   delete node;
		   node = temp;
	   }
	   else if (node->right != NULL)
	   {
		   TreeNode *temp = node->right;
		   delete node;
		   node = temp;
	   }
   }
   else if (direction == 'r')
   {
	   TreeNode *temp = leftmostChild(node);
	   TreeNode *tmp = prevLeftmostChild(node);
	   node->value = temp->value;
	   delete temp;
	   temp = NULL;
	   tmp->left = NULL;
   }
   else if (direction == 'l')
   {
	   TreeNode *temp = rightmostChild(node);
	   TreeNode *tmp = prevRightmostChild(node);
	   node->value = temp->value;
	   delete temp;
	   temp = NULL;
	   tmp->right = NULL;
   }
   else if (direction == 'c')
   {
	   TreeNode *temp = rightmostChild(node->left);
	   TreeNode *tmp = prevRightmostChild(node->left);
	   if (temp == tmp)
	   {
			node->left->right = node->right;
			TreeNode *del = node;
			node = node->left;
			delete del;
			del = NULL;
	   }
	   else
	   {
		   node->value = temp->value;
		   delete temp;
		   temp = NULL;
		   tmp->right = NULL;
	   }
   }
}
void remove(Tree *tree, int value)
{
    if (exists(tree, value))
	{
		char direction;
		if (value < tree->root->value)
			direction = 'l';
		else if (value > tree->root->value)
			direction = 'r';
		else direction = 'c';
		remove(tree->root, value, direction);
	}
	else std::cout << "\nNo such value\n\n";
}
void printInAscendingOrder (TreeNode *node)
{
	if (node->left != NULL && node->right != NULL)
	{
		printInAscendingOrder(node->left);
		std::cout << node->value << " ";
		printInAscendingOrder(node->right);
	}
	else if (node->left != NULL)
	{
		printInAscendingOrder (node->left);
		std::cout << node->value << " ";
	}
	else 
	{
		std::cout << node->value << " ";
		if (node->right != NULL)
			printInAscendingOrder (node->right);		
	}
}
void printInAscendingOrder (Tree *tree)
{
	if (tree->root != NULL)
		printInAscendingOrder (tree->root);
	else std::cout << "\nSet is empty\n\n";
}
void printInDescendingOrder (TreeNode *node)
{
	if (node->left != NULL && node->right != NULL)
	{
		printInDescendingOrder(node->right);
		std::cout << node->value << " ";
		printInDescendingOrder(node->left);
	}
	else if (node->right != NULL)
	{
		printInDescendingOrder (node->right);
		std::cout << node->value << " ";
	}
	else 
	{
		std::cout << node->value << " ";
		if (node->left != NULL)
			printInDescendingOrder (node->left);		
	}
}
void printInDescendingOrder (Tree *tree)
{
	if (tree->root != NULL)
		printInDescendingOrder (tree->root);
	else std::cout << "\nSet is empty\n\n";
}
void destroyTree (Tree *tree)
{
	destroy(tree->root);
}
void destroy (TreeNode *node)
{
		if (node != NULL && node->left == NULL && node->right == NULL)
		{
		   delete node;
		   node = NULL;
		}
		else if (node != NULL && node->left == NULL && node->right != NULL)
		{
		   destroy(node->right);
		   delete node;
		   node = NULL;
		}
		else if (node != NULL && node->left != NULL && node->right == NULL)
		{
			destroy(node->left);
			delete node;
			node = NULL;
		}
		else if (node != NULL && node->left != NULL && node->right != NULL)
		{
		   destroy(node->right);
		   destroy(node->left);
		   delete node;
		   node = NULL;
		}
}