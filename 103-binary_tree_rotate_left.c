#include "binary_trees.h"

/**
 * binary_tree_rotate_left - This function  performs a left-rotation
 *			     on a binary tree
 * @tree: Pointer to the the root node of the tree to rotate
 *
 * Return: A pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *parent, *left;

	if (tree->right)
	{
		parent = tree->right;
		left = parent->left;

		rotate_parent(tree, parent);
		tree->right = left;
		if (left)
			left->parent = tree;
		parent->left = tree;
		tree->parent = parent;
		return (tree->parent);

	}
	return (tree);
}

/**
 * rotate_parent - This is a helper function to perform a left-rotation
 *		   on a binary tree
 * @node: A Pointer to the the root node of the tree to rotate
 * @parent: A pointer to the newly made parent of the node
 *
 * Return: A pointer to the new root node of the tree once rotated
 */

void rotate_parent(binary_tree_t *node, binary_tree_t *parent)
{
	parent->parent = node->parent;
	if (node->parent)
	{
		if (node->parent->left == node)
			node->parent->left = parent;
		else
			node->parent->right = parent;
	}
}
