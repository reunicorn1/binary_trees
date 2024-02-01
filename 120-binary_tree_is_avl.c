#include "binary_trees.h"
#include <stdlib.h>
#include <limits.h>


int binary_tree_is_avl(const binary_tree_t *tree);
int is_avl(const binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
int is_bst(const binary_tree_t *tree, int min, int max);
int binary_tree_balance(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - This function checks if a binary tree is
 *			a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL, and 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree || !binary_tree_is_bst(tree))
		return (0);
	return (is_avl(tree));
}

/**
 * is_avl - This function checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL, and 0 otherwise
 */

int is_avl(const binary_tree_t *tree)
{
	if (tree)
	{
		if (!(is_avl(tree->left) && is_avl(tree->right)))
			return (0);
		if (abs(binary_tree_balance(tree)) > 1)
			return (0);
	}
	return (1);
}

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
			return (0);
		else
			return (is_bst(tree->left, min, tree->n - 1) &&
				is_bst(tree->right, tree->n + 1, max));
	}
	return (1);
}

/**
 * binary_tree_balance - This function measures the balance factor
 *                       of a binary tree
 *
 * @tree: Pointer to the root node
 *
 * Return: the balance factor measurement of the tree
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int hl = 0, hr = 0;

	if (tree)
	{
		if (tree->right)
			hr = binary_tree_height(tree->right) + 1;
		if (tree->left)
			hl = binary_tree_height(tree->left) + 1;
	}
	return (hl - hr);
}


/**
 * binary_tree_height - This function measures the height of a binary tree
 *
 * @tree: Pointer to the root node
 *
 * Return: the height measurement of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t hl = 0, hr = 0, max = 0;

	if (tree)
	{
		if (tree->left)
			hl = binary_tree_height(tree->left) + 1;
		if (tree->right)
			hr = binary_tree_height(tree->right) + 1;
		max = hl >= hr ? hl : hr;
	}
	return (max);
}
