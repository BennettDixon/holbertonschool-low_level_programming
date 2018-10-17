#include <stdlib.h>
/**
 * int_index - gets the index of an array element
 * @array: array to search through
 * @size: size of array (num of elements)
 * @cmp: comparison function to determine if element found
 *
 * Return: integer representing index of element found in array
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size <= 0)
		return (-1);
	if (array == NULL || cmp == NULL)
		return (-1);
	while (i < size)
	{
		if (cmp(array[i]))
			return (i);
		i++;
	}
	return (-1);
}
