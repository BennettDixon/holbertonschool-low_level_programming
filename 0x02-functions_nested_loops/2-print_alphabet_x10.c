void print_alphabet_x10(void);

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
