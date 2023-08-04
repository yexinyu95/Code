#include<stdio.h>

int main(void)
{
    printf("please input a number");
    printf("q to quit.\n");

    int num;
    int sum = 0;
    scanf("%d", &num);

    int status;
    status = scanf("%d", &num);

    while(status == 1)
    {
        sum = sum + num;
        printf("please input next number(q to quit) .\n");
        status = scanf("%d", &num);
    }

    printf("the sum is %d.\n", sum);

    return 0;
}