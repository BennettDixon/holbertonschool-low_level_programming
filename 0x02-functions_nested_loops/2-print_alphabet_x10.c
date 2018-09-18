/**
 * print_alphabet_x10 - print alphabet 10 times
 *
 * Return: always void
 */
void print_alphabet_x10(void)
{
	int i;

	i = 0;

	while (i < 10)
	{
		int ch = 'a';

		while (ch <= 'z')
		{
			putchar(ch++);
		}
		putchar('\n');
		i++;
	}
}
