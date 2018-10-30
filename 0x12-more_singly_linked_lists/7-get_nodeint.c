#include "lists.h"
/**
 * get_nodeint_at_index - gets a node of linked list at specific index
 * @head: head of list
 * @index: index to pull node from
 *
 * Return: pointer to node at specified index, NULL if not found
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int ctr = 0;
	listint_t *temp_h;

	if (!head) /* EMPTY list */
		return (NULL);
	temp_h = head;
	while (temp_h)
	{
		if (ctr == index)
			return (temp_h);
		temp_h = temp_h->next;
		ctr++;
	}
	return (NULL); /* didn't find node */
}
