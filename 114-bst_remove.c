#include "binary_trees.h"
#include <stdio.h>

/**
 * bst_remove - This function removes a node from a Binary Search Tree
 * @root: A Pointer to the root node of the tree to remove its nose
 * @value: the value to be removed
 *
 * Return: A pointer to the new root node of the tree after removal
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *new_root;

	node = bst_search(root, value);
	if (!node)
		return (root);
	new_root = remove_node(root, node);
	return (new_root);
}

/**
 * remove_node - This function removes a node from a Binary Search Tree
 * @root: A Pointer to the root node of the tree to remove its nose
 * @node: A Pointer to the node to be removed
 *
 * Return: A pointer to the new root node of the tree after removal
 */

bst_t *remove_node(bst_t *root, bst_t *node)
{
	bst_t *tmp;

	if (!(!node || node->right || node->left)) /*checks if the node is leaf*/
	{
		if (root == node)
			root = NULL;
		if (node->parent->left == node)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
	}
	else if (node->left && !node->right)
	{
		if (root == node)
			root = node->left;
		tmp = node->left;
		switching(node, tmp);
		tmp->left = NULL;
	}
	else if (node->right && !node->left)
	{
		if (root == node)
			root = node->right;
		tmp = node->right;
		switching(node, tmp);
		tmp->right = NULL;
	}
	else
	{
		tmp = min_node(node->right);
		if (root == node)
			root = tmp;
		printf("%d\n", tmp->n);
		switching(node, tmp);
		return (remove_node(root, node));
	}
	free(node);
	return (root);
}

/**
 * min_node - This function returns the least value in a tree
 * @node: A pointer of the subtree to look in
 *
 * Return: A pointer to the new root node of the tree after removal
 */

bst_t *min_node(bst_t *node)
{
	if (node->left)
		return (min_node(node->left));
	return (node);
}


/**
 * switching - This function switches between two nodes in the tree
 * @a: A Pointer to the first node to be switched
 * @b: A pointer to the second node to be switched
 *
 * Return: Nothing
 */
void switching(bst_t *a, bst_t *b)
{
	bst_t *parenta, *parentb, *lefta, *leftb, *righta, *rightb;

	if (!a || !b)
		return;
	parenta = a->parent;
	parentb = b->parent;
	lefta = a->left;
	righta = a->right;
	leftb = b->left;
	rightb = b->right;

	if (lefta)
		lefta->parent = b;
	if (righta)
		righta->parent = b;
	if (leftb)
		leftb->parent = a;
	if (rightb)
		rightb->parent = a;
	if (parenta)
	{
		if (parenta->left == a)
			parenta->left = b;
		else
			parenta->right = b;
	}
	if (parentb)
	{
		if (parentb->left == b)
			parentb->left = a;
		else
			parentb->right = a;
	}
	a->parent = parentb;
	b->parent = parenta;
	a->left = leftb;
	a->right = rightb;
	b->left = lefta;
	b->right = righta;
}


/**
 * bst_search - a function that searches for a value in a Binary Search Tree
 * @tree:  is a pointer to the root node of the BST to search
 * @value: is the value to search in the tree
 * Return:  return a pointer to the node containing a value equals to value
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);
	else if (value <= tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}
