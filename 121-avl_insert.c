#include "binary_trees.h"
#include <stdlib.h>

/**
 * r_bst_insert -  a function that inserts a value in a Binary Search Tree
 * @tree: is a double pointer to the root node of the BST to insert the value
 * @value: is the value to store in the node to be inserted
 * Return: Your function must return 1 if tree is a valid BST, and 0 otherwise
 * If tree is NULL, return 0
 */

bst_t *r_bst_insert(bst_t **tree, int value)
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

	if (value <= (*tree)->n)
	{
		new_node = r_bst_insert(&((*tree)->left), value);
		(*tree)->left->parent = *tree;
	}
	else
	{
		new_node = r_bst_insert(&((*tree)->right), value);
		(*tree)->right->parent = *tree;
	}

	return (new_node);
}


/**
 * binary_tree_rotate_left_right - Performs a left-right
 * rotation on a binary tree.
 *
 * @tree: Pointer to the root node of the tree to rotate.
 * Return: A pointer to the new root node of the tree once rotated.
 */

binary_tree_t *binary_tree_rotate_left_right(binary_tree_t *tree)
{
	if (!tree || !tree->left || !tree->left->right)
		return (NULL);

	tree->left = binary_tree_rotate_left(tree->left);
	return (binary_tree_rotate_right(tree));

}

/**
 * binary_tree_rotate_right_left - Performs a right-left
 * rotation on a binary tree.
 *
 * @tree: Pointer to the root node of the tree to rotate.
 * Return: A pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right_left(binary_tree_t *tree)
{
	if (!tree || !tree->right || !tree->right->left)
		return (NULL);

	tree->right = binary_tree_rotate_right(tree->right);
	return (binary_tree_rotate_left(tree));

}

/**
 * avl_insert - Inserts a value into an AVL Tree.
 *
 * @tree: Double pointer to the root node of the AVL tree
 * for inserting the value.
 *        If the address stored in tree is NULL,
 *        the created node must become the root node.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 * Description:
 * - Inserts a new node into the AVL tree based on the given value.
 * - If the address stored in tree is NULL, the created node
 *   becomes the root of the tree.
 * - The resulting tree after insertion must be a balanced AVL Tree.
 * - Balancing AVL tree involves performing rotations
 *   (right, left, right-left, left-right) as needed.
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *magic_node;
	int balance;

	magic_node = r_bst_insert(&(*tree), value);

	balance = binary_tree_balance(magic_node);

	if (balance > 1)
	{
		if (value < magic_node->left->n)
			return (binary_tree_rotate_right(magic_node));
		else
			return (binary_tree_rotate_left_right(magic_node));
	}
	else if (balance < -1)
	{
		if (value > magic_node->right->n)
			return (binary_tree_rotate_left(magic_node));
		else
			return (binary_tree_rotate_right_left(magic_node));
	}
	else
		return (magic_node);
}
