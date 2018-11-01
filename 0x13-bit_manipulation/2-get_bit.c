#include "holberton.h"
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
