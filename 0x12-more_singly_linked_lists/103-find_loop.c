#include "lists.h"
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *adv_once = head, *adv_twice = head;

	while (adv_once && adv_twice && adv_twice->next)
	{
		adv_once = adv_once->next;
		adv_twice = adv_twice->next->next;
		if (adv_once == adv_twice)
		{
			return (adv_once);
		}
	}
	return (NULL);
}
