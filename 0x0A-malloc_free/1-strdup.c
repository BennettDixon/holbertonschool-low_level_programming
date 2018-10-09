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
	char *dup, *strT;
	char *dupStart;
	int strSize = 0;

	if (str == NULL) /* null string */
		return (NULL);
	strT = str;
	while (*(str + strSize))
		strSize++;
	dup = malloc(sizeof(*str) * (strSize + 1));
	if (dup == NULL)
		return (NULL);
	dupStart = dup;
	while (*strT)
		*dup++ = *strT++;
	*dup = '\0'; /* null byte */
	return (dupStart);
}
