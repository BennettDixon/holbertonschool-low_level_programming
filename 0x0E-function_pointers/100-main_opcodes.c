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
	return (0);
}
