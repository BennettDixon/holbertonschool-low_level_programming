#include "lists.h"
/**
 * free_listint2 - frees a linked list and sets head to NULL
 * @head: double pointer to head of list
 *
 * Return: always void.
 */
void free_listint2(listint_t **head)
{
	if (head == NULL)
		return;
	while (*head)
	{
		free(*head);
		*head = (*head)->next;
	}
	head = NULL;
}
