#pragma once
struct TreeNode
{
    char symbol;
	int value;
    TreeNode *left;
    TreeNode *right;
};
struct Tree
{
    TreeNode *root;
};
Tree *createTree();
void addSymbol(Tree *tree, char symbol);
void addValue(Tree *tree, int value);
void print (Tree *tree);
int result (Tree *tree);