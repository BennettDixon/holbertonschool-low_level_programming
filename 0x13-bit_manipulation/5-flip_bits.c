/**
 * flip_bits - gets number of bits needed to flip for n to equal m
 * @n: number to see how many bit flips are needed to equal m for
 * @m: number to set other to equal given bit flips
 *
 * Return: number of bit flips needed for one number to equal the other
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int n_flips = 0;
	unsigned long int xor = (n ^ m);
	unsigned long int mask = 0x01;

	while (mask <= xor)
	{
		if (mask & xor) /* bit is lit in xor, will need to flip */
			n_flips++;
		mask = mask << 1;
	}
	return (n_flips);
}
