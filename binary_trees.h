#ifndef BINARY_TREES_H
#define	BINARY_TREES_H


/*________ Library Includes ________*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



/*________ Data Structures ________*/

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */

struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/**
 * struct queue_node - doubly linked list representation of a stack (or queue)
 * @data: A binary tree element
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct queue_node
{
	struct binary_tree_s *data;
	struct queue_node *next;
} queue_node_t;

/**
 * struct queue_s - doubly linked list representation of a stack (or queue)
 * @front: Pointer to the front of the queue
 * @rear: Pointer to the rear of the queue
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct queue_s
{
	struct queue_node *front;
	struct queue_node *rear;
} queue_t;


/*________ Function Prototypes ________*/

/*== binary_tree_print.c ==*/
void binary_tree_print(const binary_tree_t *tree);

/*== 0-binary_tree_node.c ==*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/*== 1-binary_tree_insert_left.c ==*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/*== 2-binary_tree_insert_right.c ==*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/*== 3-binary_tree_delete.c ==*/
void binary_tree_delete(binary_tree_t *tree);

/*== 4-binary_tree_is_leaf.c ==*/
int binary_tree_is_leaf(const binary_tree_t *node);

/*== 5-binary_tree_is_root.c ==*/
int binary_tree_is_root(const binary_tree_t *node);

/*== 6-binary_tree_preorder.c ==*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/*== 7-binary_tree_inorder.c ==*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/*== 8-binary_tree_postorder.c ==*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/*== 9-binary_tree_height.c ==*/
size_t binary_tree_height(const binary_tree_t *tree);

/*== 10-binary_tree_depth.c ==*/
size_t depth(const binary_tree_t *tree, size_t d);
size_t binary_tree_depth(const binary_tree_t *tree);

/*== 11-binary_tree_size.c ==*/
size_t binary_tree_size(const binary_tree_t *tree);

/*== 12-binary_tree_leaves.c ==*/
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t leaves(const binary_tree_t *tree, size_t l);

/*== 13-binary_tree_nodes.c ==*/
size_t binary_tree_nodes(const binary_tree_t *tree);

/*== 14-binary_tree_balance.c ==*/
int binary_tree_balance(const binary_tree_t *tree);

/*== 15-binary_tree_is_full.c ==*/
int binary_tree_is_full(const binary_tree_t *tree);

/*== 16-binary_tree_is_perfect.c ==*/
int binary_tree_is_perfect(const binary_tree_t *tree);
int perfect(const binary_tree_t *tree, size_t height, size_t level);

/*== 17-binary_tree_sibling.c ==*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/*== 18-binary_tree_uncle.c ==*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/*== 100-binary_trees_ancestor.c ==*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second);

/*
 * == 101-binary_tree_levelorder.c ==
 * void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
 * void levelorder(const binary_tree_t *tree, size_t level, void (*func)(int));
 */

/*== 102-binary_tree_is_complete.c ==*/
int binary_tree_is_complete(const binary_tree_t *tree);
int countNodes(const binary_tree_t *tree);
int binary_tree_is(const binary_tree_t *tree, int index, int num_nodes);


/*== 101-levelorder_queue.c ==*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
void levelorder(const binary_tree_t *tree, size_t level, void (*func)(int));
void enqueue(queue_t *queue, const binary_tree_t *data);
binary_tree_t *dequeue(queue_t *queue);
void freeAll(queue_t *queue);
queue_t *createQueue(void);


/*== 103-binary_tree_rotate_left.c ==*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
void rotate_parent(binary_tree_t *tree, binary_tree_t *parent);

/*== 104-binary_tree_rotate_right.c ==*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);


/*== 110-binary_tree_is_bst.c ==*/
int binary_tree_is_bst(const binary_tree_t *tree);
int is_bst(const binary_tree_t *tree, int min, int max);

/*== 111-bst_insert.c ==*/
bst_t *bst_insert(bst_t **tree, int value);
bst_t *insert_to_bst(bst_t **tree, int value, int min, int max);

/*== 112-array_to_bst.c ==*/
bst_t *array_to_bst(int *array, size_t size);


/*== 113-bst_search.c ==*/
bst_t *bst_search(const bst_t *tree, int value);


/*== 114-bst_remove.c ==*/
bst_t *bst_remove(bst_t *root, int value);
bst_t *min_node(bst_t *node);
bst_t *remove_node(bst_t *root, bst_t *node);
int delete_case(bst_t *root);
int successor(bst_t *node);

/*== 120-binary_tree_is_avl.c ==*/
int binary_tree_is_avl(const binary_tree_t *tree);
int is_avl(const binary_tree_t *tree);

/*== 121-avl_insert.c ==*/
avl_t *avl_insert(avl_t **tree, int value);

/*== 122-array_to_avl.c ==*/
avl_t *array_to_avl(int *array, size_t size);

/*== 123-avl_remove.c ==*/
avl_t *avl_remove(avl_t *root, int value);

/*== 124-sorted_array_to_avl.c ==*/
avl_t *sorted_array_to_avl(int *array, size_t size);
void sorted_avl(avl_t **root, int *array, int min, int max);

/*== 130-binary_tree_is_heap.c ==*/
int binary_tree_is_heap(const binary_tree_t *tree);
int is_heap(const binary_tree_t *tree);
int is_heapified(const binary_tree_t *tree);

/*== 131-heap_insert.c ==*/
heap_t *heap_insert(heap_t **root, int value);
void heapify_up(heap_t *node);
heap_t *find_parent(heap_t *root);
heap_t *siftUp(heap_t **node);


/*== 132-array_to_heap.c ==*/
heap_t *array_to_heap(int *array, size_t size);

/*== 133-heap_extract.c==*/
int heap_extract(heap_t **root);
void switch_node(heap_t **a, heap_t **b);
void _switch_node(heap_t **a, heap_t **b);
void _enqueue(queue_t *queue, const binary_tree_t *data);
binary_tree_t *_dequeue(queue_t *queue);
void _freeAll(queue_t *queue);
void siftDown(heap_t **node);

/*== 134-heap_to_sorted_array.c ==*/
int *heap_to_sorted_array(heap_t *heap, size_t *size);

#endif
