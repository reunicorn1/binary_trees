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
	size_t d = 0;

	if (tree)
	{
		if (tree->parent)
			d = binary_tree_depth(tree->parent) + 1;
	}
	return (d);
}
