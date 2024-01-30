#include "binary_trees.h"

/**
 * binary_tree_balance - This function measures the balance factor
 *                       of a binary tree
 *
 * @tree: Pointer to the root node
 *
 * Return: the balance factor measurement of the tree
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int hl = 0, hr = 0;

	if (tree)
	{
		if (tree->right)
			hr = binary_tree_height(tree->right) + 1;
		if (tree->left)
			hl = binary_tree_height(tree->left) + 1;
	}
	return (hl - hr);
}


/**
 * binary_tree_height - This function measures the height of a binary tree
 *
 * @tree: Pointer to the root node
 *
 * Return: the height measurement of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t hl = 0, hr = 0, max = 0;

	if (tree)
	{
		if (tree->left)
			hl = binary_tree_height(tree->left) + 1;
		if (tree->right)
			hr = binary_tree_height(tree->right) + 1;
		max = hl >= hr ? hl : hr;
	}
	return (max);
}
