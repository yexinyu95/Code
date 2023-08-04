#include <stdio.h>

int main (void)
{

/*    char ch;
    int  a_count, b_count, c_count, d_count, e_count;
    
    a_count = b_count = c_count = d_count = e_count = 0;

    printf("Enter some text; enter # to quit.\n");

    ch = getchar();
    while (ch != '#')
    {
        switch (ch)
        {
            case 'a':
            case 'A': a_count++;
                      break;
            case 'b':
            case 'B': b_count++;
                      break;
            case 'c':
            case 'C': c_count++;
                      break;
            case 'd':
            case 'D': d_count++;
                      break;       
            case 'e':
            case 'E': e_count++;
                      break;   
            default:  break;                                                                                      
        }
        ch = getchar();
    }
    printf("number of letters: a = %d, b = %d, c = %d, d = %d, e = %d.\n", a_count, b_count, c_count, d_count, e_count);
*/

    int choice;
    
    printf("Enter a number: \n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1 : printf("Number one.\n"); break;
    case 2 : printf("Number two.\n"); 
    case 3 : printf("Number three. \n"); break;
    default: printf("Other input. \n"); break;
    }

    return 0;

}