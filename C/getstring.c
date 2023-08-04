#include <stdio.h>
#include <string.h>

//assign a string from stdin to str, the max string length is n,
char *getstring(char *str, int n)
{
    char *str1;
    char *find;

    str1 = fgets(str, n, stdin);
    if (str1)
    {
        find = strchr(str, '\n');
        if (find)
            {*find = '\0';}
        else
            {while (getchar() != '\n')
                continue;
            }
    }

    return str1;
}

int main(void)
{
    char str1[20]; 
    printf("Enter a sentence: \n");
    getstring(str1, 20);

    puts(str1);

    return 0;

}