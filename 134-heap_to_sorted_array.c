#include "binary_trees.h"

/**
 * heap_to_sorted_array - This function converts a Binary Max heap into
 *			  a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: the address to store the size of the array
 *
 * Return: an array in descending order
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array = NULL, i;

	if (heap)
	{
		array = malloc(sizeof(int) * (*size + 1));

		for (i = 0; i < (*size - 1); i++)
			array[i] = heap_extract(&heap);
	}
	return (array);
}
