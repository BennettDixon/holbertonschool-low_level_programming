#include "lists.h"
#include <stdio.h>
/**
 * print_listint - prints the elements in linked list
 * @h: head of listint_t type
 *
 * Return: size_t, number of nodes.
 */
size_t print_listint(const listint_t *h)
{
	size_t n_nodes = 0;
	const listint_t *temp_h;

	temp_h = h;
	while (temp_h)
	{
		printf("%d\n", temp_h->n);
		temp_h = temp_h->next;
		n_nodes++;
	}
	return (n_nodes);
}
