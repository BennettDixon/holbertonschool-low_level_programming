#include "lists.h"
/**
 * pop_listint - pops a list element from the beginning of a list
 * @head: double pointer to head of list
 *
 * Return: value of n for element deleted
 */
int pop_listint(listint_t **head)
{
	listint_t *new_head;
	int n_of_deleted_head;

	if (!*head) /* HEAD is NULL, empty list */
		return (0);
	n_of_deleted_head = (*head)->n;
	new_head = (*head)->next;
	free(*head);
	*head = new_head;
	return (n_of_deleted_head);
}
