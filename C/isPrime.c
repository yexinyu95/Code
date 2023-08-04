#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>

int main(void){

    unsigned long num;
    unsigned long div;
    bool isPrime;

//  receive an input
    printf("Please enter a number: .\n");
    scanf("%lu", &num);

//  check the division
    for (div = 2, isPrime = true; (div * div) <= num; div++)
    {
        if (num % div == 0)
        {
            if ((div * div) != num)
            printf("%lu is divisible by %lu and %lu.\n", 
                    num, div, num / div);
            else
            printf("%lu is divisible by %lu.\n", num, div);
            isPrime = false;

        }
    }
    
    if (isPrime and 1)
        printf("%lu is prime.\n", num);

    return 0;
}