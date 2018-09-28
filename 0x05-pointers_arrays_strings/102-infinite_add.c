#include <stdio.h> /* debugging use */
/**
 * infinite_add - adds two numbers
 *
 * @n1: *char - first number
 * @n2: *char - second number
 * @r:  *char - buffer where result is stored
 * @size_r int - size of buffer
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	printf("first number:%s\nsecond number:%s\nbuff:%s\nsize:%d",
		n1, n2, r, size_r);
	return ("0");
}
