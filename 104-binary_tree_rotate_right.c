#include "binary_trees.h"

/**
 * binary_tree_rotate_right -  a function that performs a right-rotation on a binary tree
 * @tree:  is a pointer to the root node of the tree to rotate
 * Return: function must return a pointer to the
 * new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *node;

	if (!tree || !tree->left)
		return (NULL);

	node = tree->left;
	tree->left = node->right;

	if (node->right)
		node->right->parent = tree;
	node->parent = tree->parent;
	if (!tree->parent)
		return (node);
	if (tree == tree->parent->left)
		tree->parent->left = node;
	else
		tree->parent->right = node;
	node->right = tree;
	tree->parent = node;

	return (node);

}
