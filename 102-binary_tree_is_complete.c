#include "binary_trees.h"

/**
 * countNodes - a function that checks if a binary tree is complete
 * @tree: is a pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0 else 1
 */

int countNodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + countNodes(tree->left) + countNodes(tree->right));
}

/**
 * binary_tree_is - a function that checks if a binary tree is complete
 * @tree: is a pointer to the root node of the tree to check
 * @index: Current index of the node
 * @num_nodes: Size of the entire tree
 * Return: 1 if complete, 0 otherwise
 */

int binary_tree_is(const binary_tree_t *tree, int index, int num_nodes)
{
	if (tree == NULL)
		return (1);
	if (index >= num_nodes)
		return (0);
	return (binary_tree_is(tree->left, 2 * index + 1, num_nodes) &&
			binary_tree_is(tree->right, 2 * index + 2, num_nodes));
}

/**
 * binary_tree_is_complete - a function that checks if a binary tree
 * is complete
 * @tree: is a pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0 else 1
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int num_nodes = countNodes(tree);

	if (!tree)
		return (0);
	return (binary_tree_is(tree, 0, num_nodes));
}
