#include "lists.h"
/**
 * delete_nodeint_at_index - deletes an element of linked list at index
 * @head: head of list
 * @index: index to delete node at
 *
 * Return: 1 if succeded, -1 if it fails
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int ctr = 0;
	listint_t *temp_h, *temp_node;

	if (!*head) /* EMPTY list */
		return (-1);
	temp_h = *head;
	if (index == 0)
	{
		temp_node = temp_h->next;
		*head = temp_node;
		free(temp_h);
		return (1);
	}
	while (temp_h)
	{
		if (ctr + 1 == index) /* delete node here */
		{
			temp_node = temp_h->next;
			temp_h->next = temp_node->next;
			free(temp_node);
			return (1);
		}
		temp_h = temp_h->next;
		ctr++;
	}
	return (-1); /* didn't find node */
}
