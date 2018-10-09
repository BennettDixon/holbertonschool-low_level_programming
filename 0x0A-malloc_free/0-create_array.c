#include <stdlib.h>
/**
 * create_array - creates an array in memory and initializes it
 *
 * @size: unsigned int, size of array to be created
 * @c: char to fill array with upon initialization
 *
 * Return: pointer to beginning of array
 */
char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i = 0;

	arr = malloc(sizeof(char) * size);
	while (i < size)
	{
		*(arr + i) = c;
		i++;
	}
	return (arr);
}
