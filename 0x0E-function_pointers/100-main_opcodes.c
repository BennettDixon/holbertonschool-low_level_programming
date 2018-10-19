#include <stdlib.h>
#include <stdio.h>
/**
 * main - entry point for program
 * @argc: arg counter, number of args
 * @argv: array of pointers to args, in order given
 *
 * Return: 0 on success, 1 if argc not right, 2 if bytes is negative
 */
int main(int argc, char *argv[])
{
	int (*f)(int, char**);
	int i = 0;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	else if (atoi(argv[1]) < 0)
	{
		printf("Error\n");
		exit(2);
	}
	f = main;
	while (i < atoi(argv[1]) && (unsigned char *)*(f + i))
	{
		printf("%.2x", (unsigned char)*(f + i));
		if ((unsigned char *)*(f + (i + 1)) != 0)
			putchar(' ');
		i++;
	}
	putchar('\n');
	return (0);
}
