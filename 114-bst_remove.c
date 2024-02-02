#include "binary_trees.h"
#include <stdio.h>

/**
 * bst_remove - This function removes a node from a Binary Search Tree
 * @root: A Pointer to the root node of the tree to remove its nose
 * @value: the value to be removed
 *
 * Return: A pointer to the new root node of the tree after removal
 */

bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = delete_case(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 *delete_case - removes a node depending on its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int delete_case(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * min_node - This function returns the least value in a tree
 * @node: A pointer of the subtree to look in
 *
 * Return: A pointer to the new root node of the tree after removal
 */

bst_t *min_node(bst_t *node)
{
	if (node->left)
		return (min_node(node->left));
	return (node);
}


/**
 * successor - min node of the right subtree
 * @node: tree to check
 * Return: the min value of this tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
