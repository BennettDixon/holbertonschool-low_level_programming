/**
 * print_sign - checks if a char is alpha or not
 *
 * @n: int parameter to check
 *
 * Return: 1 if n>0, 0 if n=0, -1 if n<0
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}
