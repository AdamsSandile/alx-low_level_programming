#include "main.h"
#include "main.h"

/**
 * get_endianness - Checks the endianness.
 *
 * Return: 0.
 *         
 */
int get_endianness(void)
{
    int me= 1;
    char *ptr = (char *)&me;

    /* If the first byte is 1, the machine is little endian */
    if (*ptr == 1)
        return 1;
    else
        return 0;
}

