/**
 * _strchr - finds if char occurs in string
 *
 * @s: string to check
 * @c: character to find in s
 *
 * Return: pointer to first instance of c, otherwise NULL
 */
char *_strchr(char *s, char c)
{
	char *start = s;
	char *occurance;

	while (*s != c)
		s++;
	occurance = s;
	s = start;
	return (occurance);
}
