#include "binary_trees.h"

/**
 * binary_tree_size - gets the size of a binary tree
 * @tree: root node to draw height from for tree
 *
 * Return: size_t representing height, 0 on failure or NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);

	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);
	size += 1;
	return (size);
}
