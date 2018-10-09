#include <stdlib.h>
/**
 * _strdup - duplicates a string in memory
 *
 * @str: string to duplicate
 *
 * Return: pointer to beginning of duplicated string
 */
char *_strdup(char *str)
{
	char *dup;
	char *dupStart;
	int strSize = 0;

	if (!*str) /* null string */
		return (NULL);
	while (*(str + strSize))
		strSize++;
	dup = malloc(sizeof(char) * strSize);
	if (dup == NULL)
		return (NULL);
	dupStart = dup;
	while (*str)
		*dup++ = *str++;
	return (dupStart);
}
