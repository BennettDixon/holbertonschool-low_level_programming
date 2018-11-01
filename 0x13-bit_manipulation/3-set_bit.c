#include "holberton.h"
/**
 * set_bit - sets a bit at given index to 1
 * @n: number to set bit in
 * @index: index to set bit at
 *
 * Return: 1 if it worked, or -1 on error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 0x01;

	mask = mask << index;
	*n |= mask;
	return (1);
}
