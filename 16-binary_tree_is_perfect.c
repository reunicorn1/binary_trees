#include "binary_trees.h"

/**
 * binary_tree_is_perfect - This function checks if a binary tree
 *			    is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 if not.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0;

	if (!tree)
		return (0);
	height = binary_tree_height(tree);
	return (perfect(tree, height, 0));
}

/**
 * perfect - This function checks if a binary tree
 *	     is perfect
 * @tree: Pointer to the root node of the tree to check
 * @height: The height of the tree to be checked
 * @level: the level of the node to be checked
 *
 * Return: 1 if perfect, 0 if not.
 */

int perfect(const binary_tree_t *tree, size_t height, size_t level)
{
	if (binary_tree_is_leaf(tree))
	{
		return (height == level);
	}
	if (!tree->left || !tree->right)
		return (0);
	return (perfect(tree->left, height, level + 1) &&
			perfect(tree->right, height, level + 1));
}

/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree:  is a pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, your function must return 0 else height of tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t hl = 0, hr = 0;

	if (!tree)
		return (0);

	if (tree->left)
	{
		hl = binary_tree_height(tree->left) + 1;
	}
	if (tree->right)
	{
		hr = binary_tree_height(tree->right) + 1;
	}
	return (hl > hr ? hl : hr);
}

/**
 * binary_tree_is_leaf - This function checks if a node is a leaf
 *
 * @node: A pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node || node->right || node->left)
		return (0);
	return (1);
}
