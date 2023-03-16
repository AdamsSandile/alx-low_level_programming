#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void print_number(int *n);
int *multiply(int *a, int *b);
int *string_to_int_array(char *s, int len);
int get_number_length(int *n);
void shift_number_left(int *n, int shift);
void free_number(int *n);

/**
 * main - Entry point
 *
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Always 0 (success)
 */
int main(int argc, char **argv)
{
    int *a, *b, *c;
    int len_a, len_b, len_c, i, j;

    if (argc != 3)
    {
        printf("Error\n");
        return (1);
    }

    /* Convert arguments to arrays of integers */
    a = string_to_int_array(argv[1], len_a);
    b = string_to_int_array(argv[2], len_b);

    /* Multiply the two numbers */
    c = multiply(a, b);
    len_c = get_number_length(c);

    /* Print the result */
    if (len_c == 0)
        putchar('0');
    else
        print_number(c);

    putchar('\n');

    /* Free memory */
    free_number(a);
    free_number(b);
    free_number(c);

    return (0);
}

/**
 * multiply - Multiplies two numbers represented as arrays of integers
 *
 * @a: First number
 * @b: Second number
 *
 * Return: Pointer to the resulting number
 */
int *multiply(int *a, int *b)
{
    int *c, *tmp;
    int len_a, len_b, len_c, i, j, carry, product;

    len_a = get_number_length(a);
    len_b = get_number_length(b);
    len_c = len_a + len_b;

    /* Allocate memory for the result */
    c = malloc(sizeof(int) * (len_c + 1));
    if (c == NULL)
        return (NULL);

    /* Initialize the result to 0 */
    for (i = 0; i < len_c; i++)
        c[i] = 0;

    /* Multiply the numbers */
    for (i = len_a - 1; i >= 0; i--)
    {
        carry = 0;
        for (j = len_b - 1; j >= 0; j--)
        {
            product = a[i] * b[j] + carry + c[i + j + 1];
            c[i + j + 1] = product % 10;
            carry = product / 10;
        }
        c[i + j + 1] = carry;
    }

    /* Remove leading zeros */
    while (len_c > 0 && c[0] == 0)
    {
        tmp = c;
        c++;
        free(tmp);
        len_c--;
    }

    return (c);
}

/**
 * string_to_int_array - Converts a string of digits to an array of integers
 *
 * @s: String to convert
 * @len: Pointer to an integer to store the length of the resulting array
 *
 * Return: Pointer to the resulting array
 */
int *string_to_int_array(char *s, int len)
{
    int *a, i, j;

    len = 0;
    while (s[len] != '\0')
        len++;

    /* Allocate memory for the array */
    a = malloc(sizeof(int) * len);
    if (a == NULL)
        return (NULL);

}




