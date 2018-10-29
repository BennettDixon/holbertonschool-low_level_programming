#include "lists.h"
void free_listint2(listint_t **head)
{
	while (*head)
	{
		free(*head);
		*head = (*head)->next;
	}
	*head = NULL;
}
