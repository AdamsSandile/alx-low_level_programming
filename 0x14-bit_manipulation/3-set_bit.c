#include "main.h"

/**
 * set_bit - A function that sets a bit at given index to 1
 * @n: The number to set bit in
 * @index: The index to set bit at
 * Return: 1 if it worked, or -1 on error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int hit = 0x01;

	hit <<= index;
	if (hit == 0)
		return (-1);
	*n |= hit;
	return (1);
}
