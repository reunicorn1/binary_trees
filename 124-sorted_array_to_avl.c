#include "binary_trees.h"

/**
 * sorted_array_to_avl - This function  builds an AVL Tree from a sorted array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of element in the array
 *
 * Return: A pointer to the created AVL, or NULL in failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	if (array)
		sorted_avl(&root, array, 0, (int)size - 1);
	return (root);
}

/**
 * sorted_avl - This function  builds an AVL Tree from a sorted array
 * @root: A pointer to the root node of the AVL Tree
 * @array: A pointer to the first element of the array to be converted
 * @min: The minimum value of the range of the array
 * @max: The maximum value of the range of the array
 *
 * Return: Nothing.
 */

void sorted_avl(avl_t **root, int *array, int min, int max)
{
	if (min <= max)
	{
		bst_insert(root, array[((max-min) / 2) + min]);
		sorted_avl(root, array, min, (((max-min) / 2) + min - 1));
		sorted_avl(root, array, (((max-min) / 2) + min + 1), max);
	}
}

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
