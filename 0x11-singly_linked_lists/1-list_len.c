#include "lists.h"
size_t list_len(const list_t *h)
{
	const list_t *temp;
	size_t n_nodes = 0;

	temp = h;
	while (temp != NULL)
	{
		temp = temp->next;
		n_nodes++;
	}
	return (n_nodes);
}
