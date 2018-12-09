#include "lists.h"
#include <stdlib.h>

/**
 * create_dnode - creates a new DLL node with data
 * @n: data to add to node
 *
 * Return: pointer to newly allocated/populated node
 */
dlistint_t *create_dnode(const int n)
{
	dlistint_t *new_node = NULL;

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;

	return (new_node);
}

/**
 * insert_dnodeint_at_index - inserts a node at position
 * in a doubly linked list
 * @h: double pointer to the head, so we can modify if needed
 * @idx: index to insert new node at
 * @n: data to add to new node
 *
 * Return: pointer to new element, NULL on failure.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node = NULL, *temp = NULL;
	unsigned int i = 0;

	new_node = create_dnode(n);
	if (!new_node)
		return (NULL);
	if (!h || !(*h)) /* NULL DLL */
		*h = new_node;
	else /* DLL exists */
	{
		temp = *h;
		/* advance to pos of idx in DLL */
		while (idx != i++ && temp->next)
			temp = temp->next;
		if (temp->next)
			new_node->prev = temp->prev;
		else
			new_node->prev = temp;
		if (idx == i) /* only happens when at end of DLL */
		{
			temp->next = new_node;
			new_node->prev = temp;
		}
		else if (idx == i - 1) /* insert at head or middle */
		{
			if (temp->prev)
				temp->prev->next = new_node;
			else /* head of LL */
				*h = new_node;
			temp->prev = new_node;
			new_node->next = temp;
		}
		else /* index is out of range */
		{
			free(new_node);
			return (NULL);
		}
	}
	return (new_node);
}
