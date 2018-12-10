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
	int rtrnValNeg = -10;
	int rtrnValPos = 10;
	int smallerLength = 0;

	while (*(s1 + s1Length) != '\0')
		s1Length++;
	while (*(s2 + s2Length) != '\0')
		s2Length++;

	smallerLength = (s1Length < s2Length) ? s1Length : s2Length;
	rtrnValNeg += -(smallerLength);
	rtrnValPos += smallerLength;

	if (s1Length < s2Length)
		return (rtrnValNeg);
	if (s1Length > s2Length)
		return (rtrnValPos);

	while (*s1) /*same length, so loop through one and check both */
	{
		if (*s1 < *s2)
			return (rtrnValNeg);
		if (*s1 > *s2)
			return (rtrnValPos);
		s1++;
		s2++;
	}
	return (0); /* equal */
}
