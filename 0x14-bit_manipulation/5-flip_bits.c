#include "main.h"

/**
 * flip_bits - number of bits you would need to flip
 * to get from one number to another
 * @n: parameter
 * @m: destiny
 * Return: bars
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int i, bars = 0;
	unsigned long int y = sizeof(unsigned long int) * 8;

	for (i = 0; i < y; i++)
	{
		if ((m & 1) != (n & 1))
			bars += 1;
		n = n >> 1;
		m = m >> 1;
	}
	return (bars);
}
