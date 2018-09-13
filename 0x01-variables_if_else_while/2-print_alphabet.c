#include<stdio.h>
/**
 * main - entry point fucntion
 *
 * Description: prints all lowercase characters, followed by a new line
 *
 * Return: always 0 (success)
 */
int main(void)
{
	int i;

	for (i = 97; i <= 122; i++)
		putchar(i);
	putchar('\n');
	return (0);
}
