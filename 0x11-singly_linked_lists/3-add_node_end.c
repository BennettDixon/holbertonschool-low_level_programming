#include "lists.h"
#include <string.h>
/**
 * add_node_end - adds a node to the end of a linked list
 * @head: pointer to a list_t pointer that points to the head struct
 * @str: string to add as node
 *
 * Return: pointer to new element of list, NULL on failure
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *temp;

	temp = *head;
	if (temp)
	{
		while (temp->next) /* get last ele of list, should be NULL */
		{
			temp = temp->next;
		}
	}
	new_node = malloc(sizeof(list_t));
	if(!new_node)
		return (NULL);
	new_node->len = strlen(str);
	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	if (temp)
		temp->next = new_node;
	else
		*head = new_node;
	return (new_node);
}
