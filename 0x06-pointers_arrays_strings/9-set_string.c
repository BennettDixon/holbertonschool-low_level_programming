/**
 * set_string - sets a pointer to a string
 *
 * @s: pointer to pointer of type char
 * @to: pointer to beginning of string to set
 *
 * Return: always void
 */
void set_string(char **s, char *to)
{
	*s = to;
}
