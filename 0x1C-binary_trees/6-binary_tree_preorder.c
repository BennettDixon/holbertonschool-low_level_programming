#include "binary_trees.h"

/**
 * binary_tree_preorder - traverses a tree in pre-order calling func
 * @tree: const pointer to root node to begin traversal at
 * @func: function to call on tree node's data
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
