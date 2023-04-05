#include<stdio.h>
#include<string.h>


int main (void)
{
    char str1[30];
    printf("Input:  ");
    scanf("%s", str1);

    printf("Output: ");

    for(int i = 0, n = strlen(str1); i < n; i++)
    {
        if (str1[i] >= 'a' && str1[i] <= 'z')
        {
            printf("%c", str1[i] - 32);
        }
        else 
        {
            printf("%c", str1[i]);
        }
    }
    printf("\n");

    return 0;

}





