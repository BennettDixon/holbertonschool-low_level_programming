#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry point for program
 *
 * @argc: count of args present
 * @argv: array of char * pointing to args
 *
 * Return: always 0 (success)
 */
int main(int argc, char *argv[])
{
	int i, product = 1;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	for (i = 1; i < argc; i++)
		product *= atoi(argv[i]);
	printf("%d\n", product);
	return (0);
}
