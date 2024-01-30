#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_depth - This function measures the depth of a node
 *                     in a binary tree
 * @tree: Pointer to the node to measure its depth
 *
 * Return: the depth of the node.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t d;

	if (tree)
	{
		d = depth(tree, 0);
		return (d);
	}
	return (0);
}

/**
 * depth - This is a helper function to measure the depth of a node
 *         in a binary tree
 * @tree: Pointer to the node to measure its depth
 * @d: is the depth value
 *
 * Return: the depth of the node.
 */

size_t depth(const binary_tree_t *tree, size_t d)
{
	if (tree->parent)
		d = depth(tree->parent, d) + 1;
	return (d);
}
