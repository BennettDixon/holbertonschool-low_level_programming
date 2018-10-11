#include <stdlib.h>
/**
 * _realloc - frees and reallocates previous space
 *
 * @ptr: pointer to current block of memory
 * @old_size: old size of memory in bytes
 * @new_size: new size to be allocated in bytes
 *
 * Return: void pointer to new memory location
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *temp, *tempP;
	unsigned int i = 0;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL) /* treat as normal malloc */
	{
		ptr = malloc(new_size);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (!new_size && ptr)
	{
		free(ptr);
		return (NULL);
	}
	temp = malloc(new_size);
	tempP = ptr;
	if (old_size > new_size)
		old_size = new_size;
	for (i = 0; i < old_size; i++)
		temp[i] = tempP[i];
	free(ptr);
	return (temp);
}
