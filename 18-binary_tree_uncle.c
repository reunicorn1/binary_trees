#include "binary_trees.h"

/**
 * binary_tree_uncle - This function  finds the uncle of a node
 * @node: Pointer to the node to find its uncle.
 *
 * Return: A pointer to the uncle node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node && node->parent && node->parent->parent)
	{
		if (node->parent->parent->left == node->parent)
			return (node->parent->parent->right);
		else if (node->parent->parent->right == node->parent)
			return (node->parent->parent->left);
	}
	return (NULL);
}
