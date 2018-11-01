#include "holberton.h"
/**
 * get_bit - gets a bit, 1 or 0, at index
 * @n: number to get bit from
 * @index: index to find bit at
 *
 * Return: 1 or 0 depending if bit is lit or not
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int ret = 0;
	unsigned int i = 0;
	unsigned long int mask = 0x01;

	while (i != index)
	{
		mask = mask << 1;
		i++;
	}
	ret = ((n & mask)) ? 1 : 0;
	return (ret);
}
