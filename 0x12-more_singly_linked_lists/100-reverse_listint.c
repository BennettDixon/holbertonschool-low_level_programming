#include "lists.h"
/**
 * reverse_listint - reverses a linked list
 * @head: double pointer to head of linked list
 *
 * Return: pointer to new head of linked list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	if (!head || !*head)
		return (NULL);
	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}
	*head = prev;
	return (*head);
}
