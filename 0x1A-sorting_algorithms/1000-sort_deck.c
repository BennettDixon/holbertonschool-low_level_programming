#include "deck.h"

#include <stdio.h>
void print_deck(const deck_node_t *deck);

void qsort_deck(deck_node_t *left, deck_node_t *right, deck_node_t **deck);
deck_node_t *lomuto_part(deck_node_t *left, deck_node_t *right, deck_node_t **deck);
int card_comp(const card_t *card1, const card_t *card2);
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
	qsort_deck(*deck, end, deck);
}

/**
 * qsort_deck - quick sorts a deck of cards recursively
 * @deck: double pointer to the deck for head modification
 * @left: pointer to left (start) of linked list
 * @right: pointer to right (end) of linked list
 */
void qsort_deck(deck_node_t *left, deck_node_t *right, deck_node_t **deck)
{
	deck_node_t *first_partition = NULL;

	if (right == left)
	{
		printf("partition sorted\n");
		return;
	}

	first_partition = lomuto_part(left, right, deck);
	printf("first_partition got: [%s S:%d]\n", first_partition->card->value, first_partition->card->kind);
	printf("end of deck got: [%s S:%d]\n", right->card->value, right->card->kind);
	qsort_deck(left, first_partition->prev, deck);
	qsort_deck(first_partition->next, right, deck);
}

/**
 * lomuto_part - does lomuto partitioning for deck
 * @deck: double pointer to the deck for head modification
 * @left: pointer to left (start) of linked list
 * @right: pointer to right (end) of linked list
 *
 * Return: pointer to the new position of the pivot, spiltting partitions
 */
deck_node_t *lomuto_part(deck_node_t *left, deck_node_t *right, deck_node_t **deck)
{
	deck_node_t *temp_l, *temp_r, *pivot, *tmp_n;

	temp_l = temp_r = left;
	pivot = right;
	while (temp_r && temp_l && temp_r != pivot)
	{
		tmp_n = temp_r->next;
		if (!card_comp(temp_r->card, pivot->card))
		{
			temp_l = temp_l->next;
			swap_card(temp_l->prev, temp_r, deck);
			if (temp_l == temp_r)
				temp_l = temp_l->next;
			print_deck(*deck);
		}
		if (temp_r != tmp_n)
			temp_r = tmp_n;
		else
			temp_r = temp_r->next;
	}
	if (card_comp(temp_l->card, pivot->card))
	{
		printf("broke part loop, swapping back pivot\n");
		swap_card(temp_l, pivot, deck);
		print_deck(*deck);
		return (pivot);
	}
	return (temp_l);
}

/**
 * card_comp - compares to cards evaluting suit and value
 * @card1: card 1 to compare with card 2
 * @card2: card 2 to compare with card 1
 *
 * Return: 0 if card 1 is greater than card 2
 *         1 if card 2 is greater than card 1
 *        -1 on errror
 */
int card_comp(const card_t *card1, const card_t *card2)
{
	int c1_val, c2_val;
	BOOL suit_greater = FALSE;
	BOOL suit_equal = FALSE;

	printf("CARD_COMP comparing [%s S:%d] with [%s S:%d]\n", card1->value, card1->kind, card2->value, card2->kind);
	switch (card1->kind)
	{
		case 0:
			if (card2->kind == 0)
				suit_equal = TRUE;
			suit_greater = TRUE;
			break;
		case 1:
			if (card2->kind != 0)
				suit_greater = TRUE;
			if (card2->kind == 1)
				suit_equal = TRUE;
			break;
		case 2:
			if (card2->kind != 1 &&
			    card2->kind != 0)
				suit_greater = TRUE;
			if (card2->kind == 2)
				suit_equal = TRUE;
			break;
		case 3:
			if (card2->kind == 3)
				suit_greater = TRUE;
				suit_equal = TRUE;
			break;
	}

	if (!suit_greater)
		return (1);
	else if (!suit_equal) /* suits were not equal and c1 > c2*/
		return (0);
	c1_val = atoi(card1->value);
	c2_val = atoi(card2->value);
	if (c1_val <= 1 || c1_val > 10)
	{
		printf("card 1 is royal\n");
		if (c2_val <= 1 || c2_val > 10)
		{
			printf("card 2 is royal\n");
			if (card1->value[0] == 'K')
				return (0);
			if (card2->value[0] == 'K')
				return (1);
			if (card1->value[0] == 'Q')
				return (0);
			if (card2->value[0] == 'Q')
				return (1);
			if (card1->value[0] == 'J')
				return (0);
			if (card2->value[0] == 'J')
				return (1);
			if (card2->value[0] == 'A')
				return (0);
			return (-1);
		}
	}
	if (card1->value[0] == 'A')
		return (1);
	else if (card2->value[0] == 'A')
		return (0);
	else if (c2_val <= 1 || c2_val > 10)
		return (1);
	
	if (c1_val > c2_val)
		return (0);
	else if (c2_val > c1_val)
		return (1);
	return (-1);
}

/**
 * swap_card - swaps to card nodes in a linked list
 * IMPORTANT: do not have node1 be after node2 in the list ->
 * implementation is UNDEFINED when this is the case.
 *
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
