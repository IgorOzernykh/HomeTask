#pragma once
struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
};
struct Tree
{
    TreeNode *root;
};
Tree *createTree();
bool exists(Tree *tree, int value);
void add(Tree *tree, int value);
void remove(Tree *tree, int value);
void printInAscendingOrder (Tree *tree);
void printInDescendingOrder (Tree *tree);
void destroyTree (Tree *tree);
void destroy (TreeNode *node);