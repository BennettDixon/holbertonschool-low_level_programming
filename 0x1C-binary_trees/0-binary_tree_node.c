#include "binary_trees.h"
#include <stdlib.h>

binary_tree_t *create_orphan_node(int value);

/**
 * binary_tree_node - creates a binary tree node from parent
 * @parent: parent to create child from
 * @value: value of the node, data to store
 *
 * Return: pointer to new node OR (NULL) on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = create_orphan_node(value);
	if (parent)
	{
		new_node->parent = parent;
		if (parent->n > value)
			parent->left = new_node;
		else
			parent->right = new_node;
	}
	return (new_node);
}


/**
 * create_orphan_node - creates a node with NULL pointers and a value
 * @value: value to set as n of node
 *
 * Return: newly created orphan node
 */
binary_tree_t *create_orphan_node(int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	new_node->n = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
