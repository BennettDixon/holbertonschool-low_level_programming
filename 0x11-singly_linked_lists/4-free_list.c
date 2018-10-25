#include "lists.h"
/**
 * free_list - frees all elements in a linked list
 * @head: pointer to head element of list
 *
 * Return: always void
 */
void free_list(list_t *head)
{
	list_t *temp;

	temp = head;
	while (temp)
	{
		if (temp->str)
			free(temp->str);
		free(temp);
		temp = temp->next;
	}
}
