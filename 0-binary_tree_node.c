#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_node - This function creates a binary tree node.
 *
 * @parent: Pointer to the parent node of the node to create
 * @value: the value to put in the new node
 *
 * Return: a pointer to the new node or NULL in failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent && parent->right && parent->left)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	if (parent)
	{
		if (!parent->left)
		{
			parent->left = new;
		}
		else
		{
			parent->right = new;
		}
	}
	return (new);
}
