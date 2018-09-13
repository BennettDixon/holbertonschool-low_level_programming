#include <stdio.h>
/**
 * main - entry point for program
 *
 * Description: use putchar to print ints
 *
 * Return: always 0 (success)
 */
int main(void)
{
	int i;

	for (i = 48; i < 58; i++)
		putchar(i);
	putchar('\n');
	return (0);
}
