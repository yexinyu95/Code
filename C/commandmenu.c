#include <stdio.h>
#include <iso646.h>

char getchoice(void);

int main (void)
{
    int choice;

    while ((choice = getchoice()) != 'q')
    {
        switch (choice)
        {
            case 'a': printf("Buy low, sell high.\n");
                    break;
            case 'b': printf("Bell.\n"); 
                    break;
            case 'c': printf("Count.\n");
                    break;
            
            default: printf("Program error!\n");
                    break;
        }
    }
}


char getfirst(void)
{
    int ch;
    ch = getchar();
    while (getchar() != '\n')
    {continue;}
    return ch;
}

char getchoice(void)
{
    int ch;
    printf("Enter the letter of your choice:\n");
    printf("a. advice       b. bell\n");
    printf("c. count        q. quit\n");

    ch = getfirst();

    while ((ch < 'a' or ch > 'c') and ch != 'q')
    {
        printf("Please respond with a, b, c or q.\n");
        ch = getfirst();
    }

    return ch;
}


