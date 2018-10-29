#include "lists.h"
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int ctr = 0;
	listint_t *temp_h;

	if (!head) /* EMPTY list */
		return (NULL);
	temp_h = head;
	while (temp_h->next)
	{
		if (ctr == index)
			return (temp_h);
		temp_h = temp_h->next;
		ctr++;
	}
	return (NULL); /* didn't find node */
}
