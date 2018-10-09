#include <stdlib.h>
/**
 * free_grid - frees a 2D array of ints previously malloc'ed
 *
 * @grid: 2D array of ints to free
 * @height: height of grid
 *
 * Return: always void
 */
void free_grid(int **grid, int height)
{
	int i = 0;

	if (grid == NULL)
		return;
	while (i < height)
		free((int *)grid[i++]);
	free(grid);
}
