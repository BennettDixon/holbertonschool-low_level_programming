#include "lists.h"
#include <string.h>
/**
 * add_nodeint - adds a node of listint_t to the head of a linked list
 * @head: pointer to a list_t pointer that points to the head struct
 * @n: integer data to put in new node
 *
 * Return: pointer to new head of list, NULL on failure
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *temp_head;

	temp_head = *head;
	*head = malloc(sizeof(listint_t));
	if (!*head)
		return (NULL);
	(*head)->n = n;
	(*head)->next = temp_head;
	return (*head);
}
