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



/*________ Function Prototypes ________*/

/*== binary_tree_print.c ==*/
void binary_tree_print(const binary_tree_t *tree);

/*== 0-binary_tree_node.c ==*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/*== 2-binary_tree_insert_right.c ==*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/*== 4-binary_tree_is_leaf.c ==*/
int binary_tree_is_leaf(const binary_tree_t *node);

/*== 6-binary_tree_preorder.c ==*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/*== 8-binary_tree_postorder.c ==*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/*== 10-binary_tree_depth.c ==*/
size_t depth(const binary_tree_t *tree, size_t d);
size_t binary_tree_depth(const binary_tree_t *tree);

/*== 12-binary_tree_leaves.c ==*/
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t leaves(const binary_tree_t *tree, size_t l);

#endif
