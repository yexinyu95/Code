#include <stdio.h>
#define  SPACE ' '


int main (void)
{

/*  use many times 
    char ch1, ch2, ch3;
    ch1 = getchar();
    ch2 = getchar();
    ch3 = getchar();
    putchar(ch1);
    putchar(ch2);
    putchar(ch3);
    printf("\n");
*/

/*  use with loop */
    char ch;
    
    ch = getchar();

    while (ch != '\n')
    {
        if (ch == SPACE)
        {putchar(ch);}
        else
        {putchar(ch + 1);}

        ch = getchar();
    }

    putchar(ch);

/* write less code
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (ch == SPACE)
        {putchar(ch);}
        else
        {putchar(ch + 1);}
    }

    putchar(ch);
*/
    return 0;
}