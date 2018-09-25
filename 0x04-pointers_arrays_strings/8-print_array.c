#include <stdio.h>
/**
 * print_array - prints an array of ints
 *
 * @a: array of integers to print
 * @n: size of array
 *
 * Return: always void
 */
void print_array(int *a, int n)
{
	int counter = 0;

	while (counter < n)
	{
		if (counter + 1 != n)
			printf("%d, ", a[counter++]);
		else
			printf("%d", a[counter++]);
	}
	putchar('\n');
}
