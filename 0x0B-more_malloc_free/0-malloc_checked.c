#include <stdlib.h>
/**
 * malloc_checked - performs a malloc, if failed exits
 *
 * @b: number of bytes to allocate
 *
 * Return: pointer to beginning of new memory
 */
void *malloc_checked(unsigned int b)
{
	void *ret;

	ret = malloc(b);
	if (ret == NULL)
		exit(98);
	return (ret);
}
