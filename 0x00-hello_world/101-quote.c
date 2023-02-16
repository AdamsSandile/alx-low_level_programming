#include <unistd.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 1
 */
int main(void)
{
    char msg[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
    ssize_t len;

    len = sizeof(msg) - 1;
    if (write(STDERR_FILENO, msg, len) != len)
    {
        /* Error occurred, return non-zero status */
        return (1);
    }
    return (1);
}
