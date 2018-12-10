/**
 * _isdigit - checks if int is digit or not
 *
 * @c: int c, represents a char
 *
 * Return: 1 if c is digit, 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57) /* ascii 0..9 values */
		return (1);
	return (0);
}
