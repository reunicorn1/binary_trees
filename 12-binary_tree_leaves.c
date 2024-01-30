#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_leaves - This function  counts the leaves in
 *                      a binary tree
 * @tree: Pointer to the node to measure its depth
 *
 * Return: the depth of the node.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t l;

	if (tree)
	{
		l = leaves(tree, 0);
		return (l);
	}
	return (0);
}

/**
 * leaves - This is a helper function to count the number of leaves
 * @tree: Pointer to the node to measure its depth
 * @l: is the number of leaves
 *
 * Return: the count of leaves.
 */

size_t leaves(const binary_tree_t *tree, size_t l)
{
	if (tree->left)
		l = leaves(tree->left, l);
	if (tree->right)
		l = leaves(tree->right, l);
	if (!tree->left && !tree->right)
		l++;
	return (l);
}
