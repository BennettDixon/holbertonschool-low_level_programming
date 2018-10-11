#include <stdlib.h>
/**
 * string_nconcat - concatenates two strings, up to n bytes of s2
 *
 * @s1: string 1 to concatenate with string 2
 * @s2: string 2 to concatenate with string 1
 * @n: number of bytes to concatenate of s2
 *
 * Return: pointer to new string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int s1Size = 0, s2Size = 0, i = 0;
	char *conc, *concStart;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (*(s1 + s1Size))
		s1Size++;
	while (*(s2 + s2Size))
		s2Size++;
	if (n > s2Size)
		n = s2Size;
	conc = malloc(sizeof(char) * (s1Size + n) + 1);
	if (conc == NULL)
		return (NULL);
	concStart = conc;
	while (*s1)
		*conc++ = *s1++;
	while (i < n)
	{
		*conc++ = *s2++;
		i++;
	}
	*conc = '\0';
	return (concStart);
}
