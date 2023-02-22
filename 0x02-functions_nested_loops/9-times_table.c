#include "myheader.h"

int main(void)
{
    times_table();
    return 0;
}

void times_table(void)
{
    int num, mult, prod;

    for (num = 0; num <= 9; num++)
    {
        printf("%d", 0);

        for (mult = 1; mult <= 9; mult++)
        {
            printf(", ");

            prod = num * mult;

            if (prod <= 9)
                printf(" ");
            else
                printf("%d", prod / 10);

            printf("%d", prod % 10);
        }
        printf("\n");
    }
}

