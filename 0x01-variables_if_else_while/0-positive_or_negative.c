#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int n = rand() % 201 - 100;

    printf("%d ", n);

    if (n > 0) {
        printf("is positive\n");
    } else if (n == 0) {
        printf("is zero\n");
    } else {
        printf("is negative\n");
    }

    return 0;
}
