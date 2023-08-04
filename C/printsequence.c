#include <stdio.h>
#include <math.h>

int main (void)
{
    double num1;
    double num2;

    int length;

    printf("input number and length:\n");
    scanf("%lf %d", &num1, &length);

    for(int j = 1; j <= length; j++)
    {
        num2 = pow (num1, j);
        printf("%d ", (int)num2);
    }



    printf("\n");


    return 0;
}