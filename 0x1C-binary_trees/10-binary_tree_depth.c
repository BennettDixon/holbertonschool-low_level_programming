#include "binary_trees.h"

/**
 * binary_tree_depth - gets the depth of a node in abinary tree
 * @tree: root node to draw height from for tree
 *
 * Return: size_t representing height, 0 on failure or NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	depth += (tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0;
	return (depth);
}
