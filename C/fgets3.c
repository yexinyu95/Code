#include <stdio.h>
int main (void)
{
    char words[10];
    int i;

    puts("Enter strings: ");

    while (fgets(words, 10, stdin) != NULL && words[0] != '\n')
    {
        i = 0;
        while (words[i] != '\n' && words[i] != '\0')
        {i++;}
        if (words[i] == '\n')
        {words[i] = '\0';}

        puts(words);
    }
    puts("Done.");
    return 0;
    
}