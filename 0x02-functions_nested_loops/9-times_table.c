#include "main.h"
/**
  * times_table - The entry point of the function
  * @void: The function takes no parameters
  *
  * Description: This is a function that prints the 9 times table, starting
  * with 0.
  */
void times_table(void)
{
	int firstnum, secondnum, multiplication_result;

	firstnum = 0;
	while (firstnum < 10)
	{
		secondnum = 0;
		while (secondnum < 10)
		{
			multiplication_result = firstnum * secondnum;
			if (secondnum != 9)
			{
				if ((multiplication_result / 10) == 0)
				{
					_putchar(multiplication_result + '0');
					_putchar(',');
					_putchar(' ');
				}
				else
				{
					_putchar((multiplication_result / 10) + '0');
					_putchar((multiplication_result % 10) + '0');
					_putchar(',');
					_putchar(' ');
				}
			}
			else
			{
				if ((multiplication_result / 10) == 0)
					_putchar(multiplication_result + '0');
				else
				{
					_putchar((multiplication_result / 10) + '0');
					_putchar((multiplication_result % 10) + '0');
				}
			}
			secondnum++;
		}
		firstnum++;
		_putchar('\n')
	}
}
