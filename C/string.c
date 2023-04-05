#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    char str1[5] = "app";
    char str2[10] = "applepie";

    printf("%p.\n", str1);
    printf("%p.\n", str2);

    strncpy(str1, str2, 4);

    puts(str1);

    return 0;
}