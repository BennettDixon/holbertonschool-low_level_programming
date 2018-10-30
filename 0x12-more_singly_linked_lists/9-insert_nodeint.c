#include "lists.h"
/**
 * insert_nodeint_at_index - inserts node at given index, preserving list
 * @head: head of list
 * @idx: index to put node at
 * @n: integer data for new node
 *
 * Return: pointer to new node at specified index, NULL if not found
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int ctr = 0;
	listint_t *temp_h, *new_node;

	if (!head || !*head) /* EMPTY list */
		return (NULL);
	temp_h = *head;
	if (idx == 0) /* insert as first element */
	{
		new_node = malloc(sizeof(listint_t));
		if (!new_node)
			return (NULL);
		new_node->n = n; /* set data */
		new_node->next = temp_h;
		*head = new_node;
		return (new_node);
	}
	while (temp_h)
	{
		if (ctr + 1 == idx) /* insert node here */
		{
			new_node = malloc(sizeof(listint_t));
			if (!new_node)
				return (NULL);
			new_node->n = n; /* set data */
			new_node->next = temp_h->next;
			temp_h->next = new_node;
			return (new_node);
		}
		temp_h = temp_h->next;
		ctr++;
	}
	return (NULL); /* didn't find node */
}
