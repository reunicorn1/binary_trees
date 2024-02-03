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
	queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
	heap_t *node;

	queue->front = NULL;
	queue->rear = NULL;
	if (root)
	{
		if (!*root)
		{
			*root = binary_tree_node(NULL, value);
			freeAll(queue);
			return (*root);
		}
		enqueue(queue, *root);
		while (queue->front)
		{
			node = dequeue(queue);
			if (!node->left)
			{
				node->left = binary_tree_node(node, value);
				freeAll(queue);
				node = siftUp(&node->left);
				return (node);
			}
			else if (!node->right)
			{
				node->right = binary_tree_node(node, value);
				freeAll(queue);
				node = siftUp(&node->right);
				return (node);
			}
			enqueue(queue, node->left);
			enqueue(queue, node->right);
		}
		freeAll(queue);
	}
	return (NULL);
}

/**
 * siftUp - Builds the maxheap using the sift-up heap sort algorithm
 * @node: pointer to node to be raised in the tree
 *
 * Return: A pointer to the new location of the raised node
 */

heap_t *siftUp(heap_t **node)
{
	if ((*node)->parent)
	{
		if ((*node)->n > (*node)->parent->n)
		{
			switch_node(node, &(*node)->parent);
			return (siftUp(&(*node)->parent));
		}
	}
	return (*node);
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
 * enqueue - adds a new node to the queue
 * @queue: a pointer to the head pf the list
 * @data: the data to be inserted into the node
 *
 * Return: Nothing.
 */

void enqueue(queue_t *queue, const binary_tree_t *data)
{
	queue_node_t *newNode = (queue_node_t *)malloc(sizeof(queue_node_t));

	if (newNode == NULL)
		exit(EXIT_FAILURE);
	newNode->data = (binary_tree_t *) data;
	newNode->next = NULL;
	if (!queue->front)
	{
		queue->front = newNode;
		queue->rear = newNode;
	}
	else
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
}

/**
 * dequeue - removed the top element of the stack
 * @queue: a pointer to the head of the list
 *
 * Return: the node that was stored.
 */

binary_tree_t *dequeue(queue_t *queue)
{
	binary_tree_t *data;
	queue_node_t *temp;

	if (!queue->front)
		return (NULL);

	data = queue->front->data;
	temp = queue->front;
	queue->front = queue->front->next;
	free(temp);
	return (data);
}

/**
 * freeAll - frees all allocated memory in cases of failure and exits
 * @queue: a pointer to the head of the stack
 *
 * Return: Nothing.
 */
void freeAll(queue_t *queue)
{
	queue_node_t *current, *temp;

	current = queue->front;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(queue);
}
