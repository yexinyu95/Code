#include <stdio.h>

void tobinary(long n);

int main(void)
{
    long number;
    printf("Input an integer: \n");
    scanf("%ld", &number);

    printf("Binary equivalent: ");
    tobinary(number);
    putchar('\n');
}


void tobinary(long n)
{
    int r;

    r = n % 2;
    if (n >= 2)
        tobinary (n / 2);
    
    putchar(r == 0 ? '0' : '1');

    return;
    
}