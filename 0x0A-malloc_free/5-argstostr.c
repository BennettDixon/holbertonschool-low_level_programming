#include <stdlib.h>
#include <stdio.h>
int _strLen(char *);
/**
 * argstostr - takes all args and concatenates them into str
 *
 * @ac: arg count, num of args in av
 * @av: array of pointers to words (args)
 *
 * Return: pointer to beginning of new string
 */
char *argstostr(int ac, char **av)
{
	int i = 0, n = 0, totalSize = 0;
	char *newStr, *startNewStr;

	if (ac <= 0 || av == NULL)
		return (NULL);

	while (i < ac)
	{
		totalSize += _strLen(av[i]) + 1; /* need space for additional new line */
		i++;
	}
	newStr = malloc(sizeof(char) * totalSize + 1); /* plus null byte */
	if (newStr == NULL) /* ran out of memory */
		return (NULL);
	startNewStr = newStr;

	i = 0;
	while (i < ac)
	{
		for (n = 0; av[i][n]; n++)
		{
			*newStr++ = av[i][n];
		}
		*newStr++ = '\n';
		i++;
	}
	*newStr = '\0';
	return (startNewStr);
}
/**
 * _strLen - returns length of string
 *
 * @s: string to check
 *
 * Return: integer, length of string
 */
int _strLen(char *s)
{
	int strL = 0;

	while (*(s + strL))
		strL++;
	return (strL);
}
