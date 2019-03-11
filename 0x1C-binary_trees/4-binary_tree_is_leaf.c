#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a tree node is a leaf
 * @node: node to check
 *
 * Return: 1 (is leaf), 0 (otherwise -- e.g null node or non leaf)
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return ((node && !node->right && !node->left) ? 1 : 0);
}
