#include "binary_trees.h"

binary_tree_t *get_sibling(binary_tree_t *node);

/**
 * binary_tree_uncle - finds the uncle of a node in a binary tree
 * @node: node to find uncle for
 *
 * Return: pointer to uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	return (get_sibling(node->parent));
}


/**
 * get_sibling - gets the sibling node to find uncle
 * @node: to get sibling from
 *
 * Return: sibling of node
 */
binary_tree_t *get_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
