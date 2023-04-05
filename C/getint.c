#include <stdio.h>

int main (void)
{
//  int getint(void) 

    int input;
    char ch;

    printf("Enter an integer.\n");

    while (scanf("%d", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
        {putchar(ch);}
        
        printf(" is not an integer, please enter an integer.\n");
    }
//  return input;

    printf("The integer is %d.\n", input);

    return 0;

}