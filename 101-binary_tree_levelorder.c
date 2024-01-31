#include "binary_trees.h"

/**
 * binary_tree_levelorder - This function goes through the binary tree
 *			    using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node.
 *
 * Return: Nothing.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = createQueue();
	binary_tree_t *node;

	if (tree && func)
	{
		enqueue(queue, tree);
		while (!isEmpty(queue))
		{
			node = dequeue(queue);
			if (node)
			{
				func(node->n);
				enqueue(queue, node->left);
				enqueue(queue, node->right);
			}
		}
	}
	freeAll(queue);
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
	queue_t_node *newNode = (queue_t_node *)malloc(sizeof(queue_t_node));
	if (newNode == NULL) {
		exit(EXIT_FAILURE);
	}
	newNode->data = (binary_tree_t*) data;
	newNode->next = NULL;
	if (isEmpty(queue)) {
		queue->front = newNode;
		queue->rear = newNode;
	} else {
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
	queue_t_node *temp;

	if (isEmpty(queue))
		return (NULL);

	data = queue->front->data;
	temp = queue->front;
	queue->front = queue->front->next;
	free(temp);
	return (data);
}

/**
 * freeAll_and_exit - frees all allocated memory in cases of failure and exits
 * @queue: a pointer to the head of the stack
 *
 * Return: Nothing.
 */
void freeAll(queue_t *queue)
{
	    queue_t_node *current, *temp;

	    current = queue->front;
	    while (current != NULL)
	    {
		    temp = current;
		    current = current->next;
		    free(temp);
	    }
	    free(queue);
}

/**
 * createQueue - This function creates a new queue
 *
 * Return: The queue.
 */

queue_t *createQueue(void)
{
	queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
	if (queue == NULL)
		exit(EXIT_FAILURE);
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}

/**
 * isEmpty - This function checks if the queue is empty
 *
 * @queue: The queue to be checked
 *
 * return: 1 or 0
 */

int isEmpty(queue_t *queue)
{
	return (queue->front == NULL);
}
