#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_bst - This function checks if a binary tree is
 *			a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree)
		return (is_bst(tree, INT_MIN, INT_MAX));
	return (0);
}

/**
 * is_bst - This function checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: the minimum value which determine the range of the tree value
 * @max: the maximum value whih determine the range of the tree value
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree)
	{
		if (tree->n < min || tree->n > max)
		{
			printf(" this value is not correct = %d\n, in relation to min = %d and max %d\n", tree->n, min, max);
			return (0);
		}
		else
			return (is_bst(tree->left, min, tree->n - 1) &&
				is_bst(tree->right, tree->n + 1, max));
	}
	return (1);
}
