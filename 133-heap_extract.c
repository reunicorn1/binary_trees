#include "binary_trees.h"

/**
 * heap_extract - This function extracts the toor node of a MAX binary heap
 * @root: A double pointer to the root node
 * Return: the value of the node that got extracted
 */
int heap_extract(heap_t **root)
{
	if (root && *root)
		return (step_down(root));
	return (0);
}

/**
 * step_down - This function extracts the toor node of a MAX binary heap
 * @root: A double pointer to the root node
 * Return: the value of the node that got extracted
 */
int step_down(heap_t **root)
{
	heap_t *node = NULL;
	int value = 0;

	if (!binary_tree_is_leaf(*root))
	{
		if ((*root)->left && (*root)->right)
		{
			node = (*root)->left->n > (*root)->right->n ?
				(*root)->left : (*root)->right;
		}
		else if ((*root)->left)
			node = (*root)->left;
		else
			node = (*root)->right;

		switch_node(root, &node);
		return (step_down(&node));
	}
	else
	{
		value = (*root)->n;
		if ((*root)->parent->right == *root)
			(*root)->parent->right = NULL;
		else
			(*root)->parent->left = NULL;
		free(*root);
		return (value);
	}
}





/**
 * switch_node - This function switches between two nodes in the tree
 * @a: A Pointer to the first node to be switched
 * @b: A pointer to the second node to be switched
 *
 * Return: Nothing
 */
void switch_node(heap_t **a, heap_t **b)
{
	(*a)->n = (*a)->n ^ (*b)->n;
	(*b)->n = (*a)->n ^ (*b)->n;
	(*a)->n = (*a)->n ^ (*b)->n;
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
	else
		return (1);
}
