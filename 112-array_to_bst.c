#include "binary_trees.h"

/**
 * array_to_bst - This function  builds a Binary Search Tree from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of element in the array
 *
 * Return: A pointer to the created BST, or NULL in failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	if (array)
	{
		for (i = 0 ; i < size; i++)
			bst_insert(&root, array[i]);
		return (root);
	}
	return (NULL);
}
