#include "binary_trees.h"

/**
 * binary_tree_nodes - a function that counts the nodes with at
 * least 1 child in a binary tree
 * @tree:  is a pointer to the root node of the tree to count
 * the number of nodes
 * Return: nodes with at least 1 child in a binary tree or
 * If tree is NULL, the function must return 0
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t num_l = 0, num_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
	{
		num_l = binary_tree_nodes(tree->left);
	}
	if (tree->right)
	{
		num_r = binary_tree_nodes(tree->right);
	}
return (num_l + num_r + (tree->left || tree->right));
}
