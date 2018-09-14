#include <stdio.h>
/**
 * main - entry point of function
 *
 * Description - print 00, 01..89 skip duplicates
 *
 * Return: always 0 (success)
 */
int main(void)
{
	int a, b;

	a = '0';
	while (a < '9')
	{
		b = a + 1;
		while (b <= '9')
		{
			putchar(a);
			putchar(b++);
			if (a != '8')
			{
				putchar(',');
				putchar(' ');
			}
		}
		a++;
	}
	putchar('\n');
	return (0);
}
