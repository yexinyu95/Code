#include <stdio.h>

int main (void)
{
    int ch;

//  use ctrl + d to end input, or ctrl + z, ctrl + c, 
    while ((ch = getchar()) != EOF)
    {
        putchar(ch);
    }

    return 0;
}