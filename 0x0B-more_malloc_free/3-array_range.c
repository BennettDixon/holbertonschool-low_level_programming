#include <stdlib.h>
#include <stdio.h>
int *fill_array_range(int *p, int min, int max);
/**
 * array_range - creates an array of integers in memory
 *
 * @min: value to start at
 * @max: value to end at
 *
 * Return: pointer to beginning of array
 */
int *array_range(int min, int max)
{
	int *ret, len = 0, temp;

	if (min > max)
		return (NULL);
	temp = min;
	while (temp <= max)
	{
		len++;
		temp++;
	}
	ret = malloc(sizeof min * len);
	if (ret == NULL)
		return (NULL);
	ret = fill_array_range(ret, min, max);
	return (ret);
}
int *fill_array_range(int *p, int min, int max)
{
	int i = 0;

	while (min <= max)
	{
		p[i] = min;
		i++, min++;
	}
	return (p);
}
