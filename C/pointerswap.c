#include <stdio.h>

void exchange (int *u, int *v);

int main (void)
{
    int x = 5, y = 10;
    printf("Originally x = %d and y = %d.\n", x, y);

    exchange(&x, &y);
    printf("Now x = %d and y = %d. \n", x, y);

    return 0;
}

void exchange (int *u, int *v)
{
    int temp;
    temp = *u;
    *u = *v;
    *v = temp;
}