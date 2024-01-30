#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_insert_left - a function that inserts a node as the
 * left-child of another node
 * @parent: the root node of the binary tree
 * @value: the data value of the new node
 * Return: pointer to the created node or
 * NULL on failure of if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newy;

	if (parent == NULL)
		return (NULL);

	newy = malloc(sizeof(binary_tree_t));
	if (newy == NULL)
		return (NULL);

	newy->n = value;
	newy->left = NULL;
	newy->right = NULL;
	newy->parent = parent;

	if (parent->left)
	{
		newy->left = parent->left;
		parent->left->parent = newy;
	}
	parent->left = newy;
	return (newy);
}
