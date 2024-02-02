#include "binary_trees.h"

/**
 * array_to_heap - This function  builds a MAX Heap Tree from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of element in the array
 *
 * Return: A pointer to the created AVL, or NULL in failure
 */

heap_t *array_to_heap(int *array, size_t size)
{
	size_t i;
	avl_t *root = NULL;

	if (array)
	{
		for (i = 0 ; i < size; i++)
			heap_insert(&root, array[i]);
	}
	return (root);
}
