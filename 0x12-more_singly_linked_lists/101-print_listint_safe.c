#include "lists.h"
#include <stdio.h>
/**
 * print_listint_safe - prints the elements in linked list
 * @h: head of listint_t type
 *
 * Return: size_t, number of nodes. Exits with 98 on failure
 */
size_t print_listint_safe(const listint_t *h)
{
	size_t n_nodes = 0;
	const listint_t *temp_h = NULL, *loop_node= NULL;

	temp_h = h;
	if (!h)
		exit(98);
	while (temp_h)
	{
		if (h->next == temp_h && n_nodes > 2)
		{
			loop_node = temp_h;
			printf("loop node: [%p] %d\n", (void *)loop_node, loop_node->n);
			exit(98);
		}
		printf("[%p] %d\n", (void *)temp_h, temp_h->n);
		temp_h = temp_h->next;
		n_nodes++;
	}
	return (n_nodes);
}
