/**
 * get_endianness - gets the endianness of the CPU running
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *)&i;

	/* c points to integer, will only pull first byte of integer */
	/* if it is 1 then it is little endian (last byte stored first) */
	/* if it is 0 then it is big endian because the data is stored last */
	if (*c)
		return (1);
	return (0);
}
