#include <stdio.h>
/**
 * _strcat - concatanates two strings
 * @dest: destination string
 * @src: string to add to end of dest
 *
 * Return: char pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int srcLength = 0;
	int counter = 0;
	char *temp = dest;
	char *tempSource = src;

	while (*dest)
		dest++;
	while (*src++)
		srcLength++;
	while (counter < srcLength)
	{
		*dest++ = *tempSource++;
		counter++;
	}
	*dest = '\0';
	return (temp);
}
