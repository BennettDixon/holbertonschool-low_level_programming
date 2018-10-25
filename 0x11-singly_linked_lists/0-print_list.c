#include "lists.h"
#include <stdio.h>
/**
 * print_list - prints a linked list
 * @h: head of list
 *
 * Return: number of nodes in list as size_t
 */
size_t print_list(const list_t *h)
{
	const list_t *temp;
	size_t n_nodes = 0;

	temp = h;
	while (temp != NULL)
	{
		printf("[%u] ", temp->len);
		if (!temp->str)
			printf("(nil)\n");
		else
			printf("%s\n", temp->str);
		temp = temp->next;
		n_nodes++;
	}
	return (n_nodes);
}
