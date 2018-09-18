#include "holberton.h"
/**
 * times_table - prints out 0..9 times table
 *
 * Return: always void
 */
void times_table(void)
{
	int i, n, pTens, pOnes, lineTotal;

	i = 0;
	pTens = 0;
	pOnes = 0;
	while (i < 10)
	{
		n = 0;
		lineTotal = 0;
		while (n < 10)
		{
			lineTotal = n * i;

			pOnes = lineTotal % 10; /* grab last digit */
			pTens = (lineTotal - pOnes) / 10;
			/* ^^grab first digit of two digit number^^ */
			if (pTens == 0 && n > 0)
				_putchar(' ');
			else if (n > 0)
				_putchar(pTens + '0');
			_putchar(pOnes + '0');
			if (n == 9)
				break;
			_putchar(',');
			_putchar(' ');
			n++;
		}
		_putchar('\n');
		i++;
	}
}
