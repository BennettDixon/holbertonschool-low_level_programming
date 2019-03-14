#include "binary_trees.h"
#include <stdio.h>

int binary_tree_not_full(const binary_tree_t *tree);

/**
 * binary_tree_is_full - checks if a binary tree is full or not
 * @tree: root node to check if tree is full from
 *
 * Return: (1) if binary tree is full (0) on anything else
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int non_full_nodes = 0;

	if (!tree)
		return (0);
	non_full_nodes = binary_tree_not_full(tree);
	return ((non_full_nodes) ? 0 : 1);
}

/**
 * binary_tree_not_full - recursive helper function to find non full nodes
 * @tree: root node of binary tree to check
 *
 * Return: number of non full nodes found
 */
int binary_tree_not_full(const binary_tree_t *tree)
{
	size_t non_full_nodes = 0;

	if (!tree)
		return (0);
	/* base case, found node that's not full */
	if ((tree->right && !tree->left) || (tree->left && !tree->right))
		return (1);
	non_full_nodes += binary_tree_not_full(tree->left);
	non_full_nodes += binary_tree_not_full(tree->right);
	return (non_full_nodes);
}
