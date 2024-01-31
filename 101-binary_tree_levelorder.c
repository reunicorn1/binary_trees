#include "binary_trees.h"

/**
 * binary_tree_levelorder - This function goes through the binary tree
 *			    using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node.
 *
 * Return: Nothing.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	height = binary_tree_height(tree);
	for (i = 0; i <= height; i++)
		levelorder(tree, i, func);
}

/**
 * levelorder - This function goes through the binary tree using
 *		level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @level: the level of the current node relative to the root
 * @func: a pointer to a function to call for each node.
 *
 * Return: Nothing.
 */

void levelorder(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree)
	{
		if (level == 0)
			func(tree->n);
		else
		{
			levelorder(tree->left, level - 1, func);
			levelorder(tree->right, level - 1, func);
		}
	}
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
