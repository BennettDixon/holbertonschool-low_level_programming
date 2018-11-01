#include "holberton.h"
void print_binary(unsigned long int n)
{
	unsigned int mask = 32768; /* 1000 0000 0000 0000 */
	char hit_rel_flag = 0;

	while (mask > 0)
	{
		if ((n & mask) == 0 && (hit_rel_flag || mask == 0x01))
			_putchar('0');
		else if ((n & mask) != 0)
		{
			_putchar('1');
			hit_rel_flag = 1;
		}
		mask = mask >> 1;
	}
}
