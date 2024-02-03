#include "binary_trees.h"


int heap_extract(heap_t **root);
void siftDown(heap_t **node);
void _switch_node(heap_t **a, heap_t **b);
void _enqueue(queue_t *queue, const binary_tree_t *data);
binary_tree_t *_dequeue(queue_t *queue);
void _freeAll(queue_t *queue);

/**
 * heap_extract - This function extracts the toor node of a MAX binary heap
 * @root: A double pointer to the root node
 * Return: the value of the node that got extracted
 */
int heap_extract(heap_t **root)
{
	queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
	heap_t *node;
	int value;

	if (root && queue && *root)
	{
		queue->front = NULL;
		queue->rear = NULL;

		_enqueue(queue, *root);
		while (queue->front)
		{
			node = _dequeue(queue);
			if (node->left)
				_enqueue(queue, node->left);
			if (node->right)
				_enqueue(queue, node->right);
		}
		_freeAll(queue);
		value = (*root)->n;
		if (*root == node)
		{
			*root = NULL;
			return (value);
		}
		_switch_node(root, &node);
		if (node->parent->right == node)
			node->parent->right = NULL;
		else
			node->parent->left = NULL;
		free(node);
		siftDown(root);
		return (value);
	}
	return (0);
}

/**
 * siftDown - Builds the maxheap using the sift-down heap sort algorithm
 * @node: pointer to the root of the tree to be installed down
 *
 * Return: A pointer to the new location of the raised node
 */
void siftDown(heap_t **node)
{
	if ((!(*node) || (*node)->right || (*node)->left))
	{
		if ((*node)->right)
		{
			if ((*node)->left->n > (*node)->right->n)
			{
				_switch_node(node, &(*node)->left);
				siftDown(&(*node)->left);
			}
			else
			{
				_switch_node(node, &(*node)->right);
				siftDown(&(*node)->right);
			}
		}
		else if ((*node)->left->n > (*node)->n)
		{
			_switch_node(node, &(*node)->left);
			siftDown(&(*node)->left);
		}
	}
}

/**
 * _switch_node - This function switches between two nodes in the tree
 * @a: A Pointer to the first node to be switched
 * @b: A pointer to the second node to be switched
 *
 * Return: Nothing
 */
void _switch_node(heap_t **a, heap_t **b)
{
	(*a)->n = (*a)->n ^ (*b)->n;
	(*b)->n = (*a)->n ^ (*b)->n;
	(*a)->n = (*a)->n ^ (*b)->n;
}

/**
 * _enqueue - adds a new node to the queue
 * @queue: a pointer to the head pf the list
 * @data: the data to be inserted into the node
 *
 * Return: Nothing.
 */

void _enqueue(queue_t *queue, const binary_tree_t *data)
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
 * _dequeue - removed the top element of the stack
 * @queue: a pointer to the head of the list
 *
 * Return: the node that was stored.
 */

binary_tree_t *_dequeue(queue_t *queue)
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
 * _freeAll - frees all allocated memory in cases of failure and exits
 * @queue: a pointer to the head of the stack
 *
 * Return: Nothing.
 */
void _freeAll(queue_t *queue)
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
