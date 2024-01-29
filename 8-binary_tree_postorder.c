#include "binary_trees.h"

/**
 * binary_tree_postorder - This function goes through a binary tree using
 *                         postorder
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: the value to put in the new node
 *
 * Return: a pointer to a function to call for each node.
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		if (tree->left)
			binary_tree_postorder(tree->left, func);
		if (tree->right)
			binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
