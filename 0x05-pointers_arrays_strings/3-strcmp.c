/**
 * _strcmp - compares two strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: -15 if s1 < s2
 *          0  if s1 = s2
 *          15 if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
	int s1Length = 0, s2Length = 0;

	if (*s1 == *s2)
		return (0); /* don't do unneeded processing if = */
	while (*(s1 + s1Length) != '\0')
		s1Length++;
	while (*(s2 + s2Length) != '\0')
		s2Length++;

	if (s1Length < s2Length)
		return (-15);
	if (s1Length > s2Length)
		return (15);

	while (*s1)
		if (*s1 < *s2)
			return (-15);
		if (*s1 > *s2)
			return (15);
	return (0); /* equal */
}
