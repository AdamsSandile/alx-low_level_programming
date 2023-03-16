#include <stdlib.h>
#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * print_error - prints an error message using _putchar
 *
 * Return: Nothing
 */
void print_error(void)
{
	int i;
	char *err = "Error\n";

	for (i = 0; i < 6; i++)
	{
		_putchar(err[i]);
	}
	exit(98);
}

/**
 * is_num - checks if provided argument is a number or not
 * @arg: given string
 *
 * Return: 1 if true, 0 if false
 */
int is_num(char *arg)
{
	int i, valid;

	valid = 1;

	for (i = 0; arg[i] != '\0'; i++)
	{
		if (arg[i] < '0' || arg[i] > '9')
		{
			valid = 0;
			break;
		}
	}
	return (valid);
}

/**
 * mul - multiplies two numbers
 * @num1: string reresented number getting multilied
 * @num2: string number getting multiplied with @num1
 * @result: pointer holding the result as integer
 * @len1: length of string num1
 * @len2: length of string num2
 *
 * Return: Nothing
 */
void mul(char *num1, int len1, char *num2, int len2, int *result)
{
	int i, j, k, l, n1, n2, c, temp;

	k = 0, l = 0;

	for (i = len1; i >= 0; i--)
	{
		c = 0;
		n1 = atoi(&num1[i]);
		l = 0;

		for (j = len2; j >= 0; j--)
		{
			n2 = atoi(&num2[j]);
			temp = n1 * n2 + result[k + l] + c;
			c = temp / 10;
			result[l + k] = temp % 10;
			l++;
		}
		if (c > 0)
			result[k + l] += c;
		k++;
	}
}

/**
 * to_str - turns a reversed int array into a char array
 * @intarr: integer array
 * @chrarr: char array to be augmented
 * @nnums: number of items inside array
 *
 * Return: nothing
 */
void to_str(int *intarr, char *chrarr, int nnums)
{
	int i, j;

	j = 0;

	for (i = nnums - 1; i >= 0; i++)
	{
		chrarr[j] = intarr[i] + '0';
		j++;
	}
	chrarr[j] = '\0';
}

/**
 * print_num - prints a char array to stdout
 * @str: string being printed using putchar
 *
 * Return: Nothing
 */
void print_num(char *str)
{
	int i;

	i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}

/**
 * main - multiplies two numbers
 * @argc: argument count
 * @argv: argument values
 *
 * Return: 0 if success, 98 if faiure or Error
 */
int main(int argc, char *argv[])
{
	int i, len1, len2, *res;
	char *newnum;

	if (argc != 3)
		print_error();
	if ((is_num(argv[1]) == 0) || (is_num(argv[2]) == 0))
		print_error();
	printf("Number was found to be valid\n");
	len1 = strlen(argv[1]), len2 = strlen(argv[2]);

	res = malloc(sizeof(int) * (len1 + len2));
	if (res == NULL)
		exit(98);
	printf("Malloc inplemented successfully\n");
	mul(argv[1], len1, argv[2], len2, res);
	printf("Number multiplied successfully\n");
	fflush(stdout);

	i = (len1 + len2); 
	while (i >= 0 && res[i] == 0)
	       	i--;
	fflush(stdout);
	printf("The value of i is %d", i);
	if (i < 0)
	{
		print_num("0");
		fflush(stdout);
		return (0);
	}
	
	newnum = malloc(sizeof(char) * (i + 1));
	if (newnum == NULL)
		exit(98);
	printf("Malloc implemented successfully for newnum\n");
	to_str(res, newnum, i);
	printf("printing number\n\n");
	fflush(stdout);
	print_num(newnum);

	return (0);
}
