#include <stdlib.h>
#include <stdio.h>
/**
 * alloc_grid - allocates memory for a 2D array of ints
 *
 * @width: number of    columns   for 2D array
 * @height: number of   rows      for 2D array
 *
 * Return: pointer to a 2D array, NULL on error
 */
int **alloc_grid(int width, int height)
{
	int **arr, i = 0, n = 0;	

	if (width <= 0 || height <= 0)
		return (NULL);
	arr = malloc(sizeof(int *) * height);
	while (i < height)
	{	
		arr[i++] = malloc(sizeof(int) * width);
		printf("allocated arr[%d]\n", i - 1);
	}
	for (i = 0; i < height; i++)
		for (n = 0; n < width; n++)
			arr[i][n] = 0;
	return (arr);
}
