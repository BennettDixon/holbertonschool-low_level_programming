#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - inserts a node at position
 * in a doubly linked list
 * @h: double pointer to the head, so we can modify if needed
 * @index: index to insert new node at
 *
 * Return: 1 (success), -1 (failure)
 */
int delete_dnodeint_at_index(dlistint_t **h, unsigned int index)
{
	dlistint_t *temp = NULL;
	unsigned int i = 0;

	if (!h || !(*h)) /* NULL DLL */
	{
		return (-1);
	}
	else /* DLL exists */
	{
		temp = *h;
		/* advance to pos of idx in DLL */
		while (index != i++ && temp)
			temp = temp->next;
		if (!temp) /* end of DLL */
			return (-1);
		if (temp->next)
			temp->next->prev = temp->prev;
		if (index == 0) /* delete at head */
			*h = temp->next;
		else
			temp->prev->next = temp->next;
		free(temp);
		return (1);
	}
	/* should never happen, here for compiler */
	return (-1);
}
