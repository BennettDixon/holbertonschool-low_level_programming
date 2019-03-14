#include "binary_trees.h"

size_t binary_tree_h(const binary_tree_t *tree);

/**
 * binary_tree_balance - calculate balance factor for tree
 * @tree: root node to calculate balance factor from
 *
 * Return: balance factor of tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (!tree)
		return (0);

	height_l = binary_tree_h(tree->left);
	height_r = binary_tree_h(tree->right);
	return (height_l - height_r);
}

/**
 * binary_tree_h - gets height of binary tree - copied
 * @tree: root node to draw height from
 *
 * Return: height of tree
 */
size_t binary_tree_h(const binary_tree_t *tree)
{
	size_t l_height = 0;
	size_t r_height = 0;

	if (!tree)
		return (0);
	l_height += (tree) ? 1 + binary_tree_h(tree->left) : 0;
	r_height += (tree) ? 1 + binary_tree_h(tree->right) : 0;
	return ((r_height > l_height) ? r_height : l_height);
}
