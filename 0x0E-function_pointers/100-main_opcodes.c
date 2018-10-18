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
	unsigned char *p;
	int i = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	else if (atoi(argv[1]) < 0)
	{
		printf("Error\n");
		return (2);
	}
	p = (unsigned char *) main;
	while (i < atoi(argv[1]) && *(p + i))
	{
		printf("%.2x", *(p + i));
		if (*(p + (i + 1)) != 0)
			putchar(' ');
		i++;
	
	}
	putchar('\n');
	return (0);
}
