/**
 * _strncat - concatanates two strings
 *
 * @dest: destination string
 * @src: string to add to end of dest
 * @n: num of bytes to take from src
 *
 * Description: only takes n bytes from src
 *
 * Return: char pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int counter = 0, srcLength = 0;
	char *temp = dest;

	while (*(src + srcLength) != '\0')
		srcLength++;
	while (*dest)
		dest++;
	if (n > srcLength)
		n = srcLength;
	while (counter < n)
	{
		*dest++ = *src++;
		counter++;
	}
	*dest = '\0';
	return (temp);
}
