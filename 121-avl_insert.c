#include "binary_trees.h"
#include <stdlib.h>

/**
 * r_insert_node - node value instertion in a AVL.
 * @tree: type **pointer of root node of the AVL tree struct.
 * @parent: parent node of struct AVL.
 * @magic_node: type**pointer left or right insertion.
 * @node_value: insertion value of the AVL.
 * Return: pointer to the magic_node root after insertion otherwise NULL
 */

avl_t *r_insert_node(avl_t **tree, avl_t *parent,
		avl_t **magic_node, int node_value);

avl_t *r_insert_node(avl_t **tree, avl_t *parent,
		avl_t **magic_node, int node_value)
{
	int balance;

	if (*tree == NULL)
		return (*magic_node = binary_tree_node(parent, node_value));
	if ((*tree)->n > node_value)
	{
		(*tree)->left = r_insert_node(&(*tree)->left, *tree, magic_node, node_value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < node_value)
	{
		(*tree)->right = r_insert_node(&(*tree)->right,
				*tree, magic_node, node_value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);
	balance = binary_tree_balance(*tree);
	if (balance > 1 && (*tree)->left->n > node_value)
		*tree = binary_tree_rotate_right(*tree);
	else if (balance > 1 && (*tree)->left->n < node_value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance < -1 && (*tree)->right->n < node_value)
		*tree = binary_tree_rotate_left(*tree);
	else if (balance < -1 && (*tree)->right->n > node_value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - inserts a value into an AVL tree.
 * @tree: type **pointer to the root node of the AVL tree to insert into.
 * @value: value to store in the node to be inserted
 * Return: inserted node, or NULL if fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *magic_node = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	r_insert_node(tree, *tree, &magic_node, value);
	return (magic_node);
}
