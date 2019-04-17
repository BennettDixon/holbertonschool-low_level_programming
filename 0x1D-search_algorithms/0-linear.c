#include <stdio.h>
#include <stdlib.h>
/**
 * linear_search - linear search implementation for arrays
 * @array: point to input array
 * @size: size of array as size_t
 * @value: value to search for
 *
 * Return: index in array where value is located
 */
int linear_search(int *array, size_t size, int value)
{
	int i;
	int _size = (int)size;

	if (!array || size <= 0)
		return (-1);
	for (i = 0; i < _size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
