#include "lists.h"
#include <stdio.h>
/**
 * listint_len - gets number of elements in linked list containing ints
 * @h: head of listint_t type
 *
 * Return: size_t, number of nodes.
 */
size_t listint_len(const listint_t *h)
{
	size_t n_nodes = 0;
	const listint_t *temp_h;

	temp_h = h;
	while (temp_h)
	{
		temp_h = temp_h->next;
		n_nodes++;
	}
	return (n_nodes);
}
