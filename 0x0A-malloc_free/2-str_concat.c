#include <stdlib.h>
/**
 * str_concat - concatenates two strings, makes new string
 *
 * @s1: string 1 to concatenate with string 2
 * @s2: string 2 to concatenate with string 1
 *
 * Return: pointer to new string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	int s1Size = 0, s2Size = 0;
	char *conc, *concStart;

	while (*(s1 + s1Size))
		s1Size++;
	while (*(s2 + s2Size))
		s2Size++;
	conc = malloc(sizeof(char) * (s1Size + s2Size - 1));
	concStart = conc;
	while (*s1)
		*conc++ = *s1++;
	while (*s2)
		*conc++ = *s2++;
	*conc = '\0';
	return (concStart);
}
