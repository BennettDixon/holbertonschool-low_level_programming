/**
 * _strlen - gets length of string
 *
 * @s: string to check length of
 *
 * Return: length of string as int
 */
int _strlen(char *s)
{
	int counter;

	counter = 0;
	while (*(s + counter) != '\0')
		counter++;
	return (counter);
}
