#include <stdio.h>
#include <math.h>

//gcc -o mathpow mathpow.c -lm

int main(void)
{
    double a, b;

    printf("input two numbers: ");
    scanf("%lf %lf", &a, &b);

    double c;
    c = pow(a, b);

    printf("%d^%d = %d.\n", (int)a, (int)b, (int)c);

    return 0;

}