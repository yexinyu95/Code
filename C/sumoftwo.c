#include<stdio.h>

int main(void)
{
    //receive calculate terms
    int times;
    printf("the number of power:.\n");
    scanf("%d", &times);

    //initialize calculation number
    double sum = 1;
    double poweroftwo = 1.0;

    //calculate use loop
    for(int i = 1; i <= times; i++)
    {
        poweroftwo = poweroftwo * 2.0;
        sum = sum + (1.0 / poweroftwo);
        printf("the sum = %.10f when terms = %d.\n", sum, i);
    }

    return 0;
}