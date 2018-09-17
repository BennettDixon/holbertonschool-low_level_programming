void print_alphabet(void);

void print_alphabet(void)
{
	int ch = 'a';

	while (ch <= 'z')
	{
		putchar(ch++);
	}
	putchar('\n');
}
