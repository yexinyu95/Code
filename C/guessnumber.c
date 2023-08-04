#include <stdio.h>

int main(void)
{
    int guess = 1;
    printf("Pick an integer form 1 to 100.\n");
    printf("Respond with n if guess is wrong, y if guess is right.\n");
    printf("is your number %d?\n", guess);

/*
    while (getchar() != 'y')
    {
        printf("is it %d?\n", ++guess);
    }

    bug: receive every char as an input and print many sentences,
*/

    while (getchar() != 'y')
    {
        printf("is it %d?\n", ++guess);
        while (getchar() != '\n')
        {
            continue;
        } 
    }
/*
    change: use another loop and continue, 
    to make all input before enter(include enter itself) 
    as a whole, 
*/

    printf("%d is the right number.\n", guess);

    return 0;
}