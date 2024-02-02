#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap to insert the value.
 * @value: The value to store in the node to be inserted.
 * Return: A pointer to the created node, or NULL on failure.
 */

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *temp;
	int tmp_value;

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return NULL;

    if (!*root)
    {
        *root = new_node;
        return new_node;
    }

    new_node->left = *root;
    *root = new_node;

    temp = new_node->left;
    while (temp->left && new_node->n > temp->left->n)
    {
        /* Swap values */
        tmp_value = new_node->n;
        new_node->n = temp->left->n;
        temp->left->n = tmp_value;

        new_node = temp->left;
        temp = new_node->left;
    }

    return new_node;
}
