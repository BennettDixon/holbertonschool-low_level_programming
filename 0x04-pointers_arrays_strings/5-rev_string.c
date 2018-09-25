/**
 * rev_string - reverses given string
 *
 * @s: string to reverse
 *
 * Return: always void
 */
void rev_string(char *s)
{
	char *end = s;
	char store;

	while (*end)
		end++; /* set pos of end pointer to point to last element */
	end = end - 1; /* set end pos to end -1 b/c end is really '\0' */
	while (s < end) /* stop once we get to last address */
	{
		store = *s; /* set store ch to s[currentPos] */
		*s++ = *end; /* set position of s = pos end, and increment s */
		*end-- = store; /* set pos of end to stored char and increment */
	}
}
