#include "binary_trees.h"
#include <stdlib.h>

binary_tree_t *create_empty_node(int value);

/**
 * binary_tree_insert_left - inserts a node to the left of parent
 * @parent: parent node to insert child under
 * @value: value to create new node data
 *
 * Return: pointer to new binary tree node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (!parent)
		return (NULL);

	new_node = create_empty_node(value);
	if (!new_node)
		return (NULL);
	new_node->parent = parent;

	/* parent contains left node, must be shifted */
	if (parent->left)
	{
		new_node->left = parent->left;
		new_node->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}

/**
 * create_empty_node - creates a node with NULL pointers and a value
 * @value: value to set as n of node
 *
 * Return: newly created orphan node
 */
binary_tree_t *create_empty_node(int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);
	new_node->n = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
