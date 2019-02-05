#include "deck.h"

void swap_card(deck_node_t *n1, deck_node_t *n2, deck_node_t **deck);

/**
 * sort_deck - sorts a deck of cards
 * @deck: deck of cards to sort
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *end = *deck;

	while (end->next)
		end = end->next;	
	swap_card((*deck)->next->next, end, deck);
}

/**
 * swap_card - swaps to card nodes in a linked list
 * @n1: node1 to swap with node2
 * @n2: node2 to swap with node1
 * @deck: double pointer to deck if head modification is needed
 */
void swap_card(deck_node_t *n1, deck_node_t *n2, deck_node_t **deck)
{
	deck_node_t *n1_prev, *n1_next, *n2_prev, *n2_next;

	if (!deck || !(*deck) || !n1 || !n2)
		return;
	n1_next = n1->next;
	n1_prev = n1->prev;
	n2_next = n2->next;
	n2_prev = n2->prev;

	if (n1_prev != n2)
		n2->prev = n1_prev;
	else
		n2->prev = n1;
	if (n1_next != n2)
		n2->next = n1_next;
	else
		n2->next = n1;
	if (n2_prev != n1)
		n2_prev->next = n1;
	if (n2_next)
		n2_next->prev = n1;
	n1->next = n2_next;
	if (n2_prev != n1)
		n1->prev = n2_prev;
	else
		n1->prev = n2;
	if (n1_prev)
		n1_prev->next = n2;
	if (n1_next != n2)
		n1_next->prev = n2;

	if (!n1->prev) /* reset head if needed */
		*deck = n1;
	else if (!n2->prev)
		*deck = n2;
}
