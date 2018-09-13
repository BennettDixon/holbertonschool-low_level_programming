#include <stdio.h>
/**
 * main - entry point for function
 *
 * Description: prints alphabet - q&e
 *
 * Return: always 0 (success)
 */
int main(void)
{
	int i;

	for (i = 97; i < 123; i++)
	{
		if (i == 101 || i == 113)
			continue;
		putchar(i);
	}
	putchar('\n');
	return (0);
}
