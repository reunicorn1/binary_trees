#include "binary_trees.h"

/**
 * binary_tree_is_full - a function that checks if a binary tree is full
 * @tree:  is a pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int left, right;
	if (!tree)
		return (0);

	if (tree->left && tree->right)
	{
		left = binary_tree_is_full(tree->left);
		right = binary_tree_is_full(tree->right);
		if (left && right)
			return (1);
	}
	if (!tree->left && !tree->right)
		return (1);
	return (0);
}
