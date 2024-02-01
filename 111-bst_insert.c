#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_insert -  a function that inserts a value in a Binary Search Tree
 * @tree: is a double pointer to the root node of the BST to insert the value
 * @value: is the value to store in the node to be inserted
 * Return: Your function must return 1 if tree is a valid BST, and 0 otherwise
 * If tree is NULL, return 0
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node;

	if (!tree)
		return (NULL);

	if (!(*tree))
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}

	if (value < (*tree)->n)
	{
		if ((*tree)->left)
			return (bst_insert(&((*tree)->left), value));
		(*tree)->left = binary_tree_node(*tree, value);
		return ((*tree)->left);
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right)
			return (bst_insert(&((*tree)->right), value));
		(*tree)->right = binary_tree_node(*tree, value);
		return ((*tree)->right);
	}
	else
		return (NULL);
}
