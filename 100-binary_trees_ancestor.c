#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure its depth
 * Return: The depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t d = 0;

    if (tree && tree->parent)
        d = binary_tree_depth(tree->parent) + 1;

    return (d);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    size_t first_depth, second_depth;

    if (!first || !second)
        return (NULL);

    if (first == second)
        return ((binary_tree_t *)first);

    if (first->parent == second)
        return ((binary_tree_t *)second);

    if (second->parent == first)
        return ((binary_tree_t *)first);

    if (first->parent == second->parent)
        return ((binary_tree_t *)first->parent);

    first_depth = binary_tree_depth(first);
    second_depth = binary_tree_depth(second);

    if (first_depth > second_depth)
        return binary_trees_ancestor(first->parent, second);

    if (first_depth < second_depth)
        return binary_trees_ancestor(first, second->parent);

    return binary_trees_ancestor(first->parent, second->parent);
}
