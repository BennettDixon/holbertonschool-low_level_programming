#include "sort.h"

void swap(int *array, size_t pos1, size_t pos2);
size_t get_pivot(int *array, size_t left, size_t right);
void sort(int *array, size_t size, size_t left, size_t right);
size_t get_partition(int *array, size_t size, size_t l, size_t r, int pvt);

/**
 * quick_sort - performs quick sort on an array
 * @array: array to sort (of ints)
 * @size: size of array (as size_t)
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	sort(array, size, 0, size - 1);
}

/**
 * sort - helper function for quick sort so it can use recurssion
 * @array: array to sort
 * @size: size of array used for printing
 * @left: left bound of array, used in recursion
 * @right: right bound of array, used in recursion
 *
 * Return: always void
 */
void sort(int *array, size_t size, size_t left, size_t right)
{
	size_t part_start = 0;
	int pvt = array[get_pivot(array, left, right)];

	if ((long int) right - (long int)left <= 0)
		return;
	part_start = get_partition(array, size, left, right, pvt);
	sort(array, size, left, part_start - 1);
	sort(array, size, part_start + 1, right);
}

/**
 * get_partition - performs recursive sorting for quick sort
 * @array: array to sort
 * @size: size of array used for printing
 * @l: index of start in array
 * @r: index of end in array
 * @pvt: value of pivot point (not index raw value as int)
 *
 * Return: partition mid point for seperate partitions
 */
size_t get_partition(int *array, size_t size, size_t l, size_t r, int pvt)
{
	size_t end;

	end = r;
	l = l - 1;

	for (r = l + 1; r < end; r++)
	{
		if (array[r] < pvt)
		{
			l++;
			if (l != r)
			{
				swap(array, l, r);
				print_array(array, size);
			}
		}
	}
	if (l + 1 != end && array[l + 1] > array[end])
	{
		swap(array, l + 1, end);
		print_array(array, size);
	}
	return (l + 1);
}

/**
 * get_pivot - gets the pivot point of an array
 * @array: array to get pivot point from (index)
 * @left: left bound of array
 * @right: right bound of array
 *
 * Return: index of pivot point in array
 */
size_t get_pivot(int *array, size_t left, size_t right)
{
	(void)array;
	(void)left;
	return (right);
}
/**
 * swap - swaps to array elements
 * @array: array to swap elements in
 * @pos1: position of element 1 to swap with element 2
 * @pos2: position of element 2 to swap with element 1
 */
void swap(int *array, size_t pos1, size_t pos2)
{
	int temp;

	temp = array[pos2];
	array[pos2] = array[pos1];
	array[pos1] = temp;
}
