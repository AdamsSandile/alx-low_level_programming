#include <unistd.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 1 (Error status)
 */
int main(void)
{
	char *msg = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
	int len = 59; /* Length of the message excluding null terminator */

	if (write(STDERR_FILENO, msg, len) != len)
		return (1);

	return (1);
}
