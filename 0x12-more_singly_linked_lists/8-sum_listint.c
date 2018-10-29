#include "lists.h"
/**
 * sum_listint - sums the n value of a linked list of listint_t
 * @head: head of list
 *
 * Return: integer represetnting sum of all n values from list
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp_h;

	if (!head)
		return (0);
	temp_h = head;
	while (temp_h)
	{
		sum += temp_h->n;
		temp_h = temp_h->next;
	}
	return (sum);
}
