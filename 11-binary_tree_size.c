#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_size - a function that measures the size of a binary tree
 * @tree:  is a pointer to the root node of the tree to measure the size
 * Return: size of a binary tree or If tree is NULL, return 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t sz = 1, szr = 0, szl = 0;

	if (!tree)
		return (0);

	if (tree->left)
	{
		szl = binary_tree_size(tree->left);
	}

	if (tree->right)
	{
		szr = binary_tree_size(tree->right);
	}
	return (sz + szr + szl);
}
