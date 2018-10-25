#include "lists.h"
#include <string.h>
/**
 * add_node - adds a node to the head of a linked list
 * @head: pointer to a list_t pointer that points to the head struct
 * @str: string to add as node
 *
 * Return: pointer to new head of list, NULL on failure
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *temp_head;

	temp_head = *head;
	*head = malloc(sizeof(*head));
	if (!*head)
		return (NULL);
	(*head)->len = strlen(str);
	(*head)->str = strdup(str);
	if (!(*head)->str)
	{	
		free(*head);
		return (NULL);
	}
	(*head)->next = temp_head;
	return (*head);
}
