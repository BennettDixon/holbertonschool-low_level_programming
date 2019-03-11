#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a tree node is a root node
 * @node: node to check
 *
 * Return: 1 (is root), 0 (otherwise -- e.g null node or non root)
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return ((node && !node->parent) ? 1 : 0);
}
