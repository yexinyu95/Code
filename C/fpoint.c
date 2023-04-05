#include <stdio.h>
#include <string.h>
#include <ctype.h>

int original(int c);
void show(int (*fpoint) (int), char *str);
void change(int (*fpoint) (int), char *str);

int main (void)
{
//  define a string for example,
    char str1[10] = "Tom Jerry";
    puts(str1);

//  basic function pointer,
    show(toupper, str1);
    change(tolower, str1);

//  use typedef to make an array of function pointer,
    typedef void (*FPOINT) (int (*fpoint) (int), char *str);
    FPOINT farray[4];
    farray[0] = show;
    farray[1] = change;

//  use array elements with footprint,
    farray[1](toupper, str1);
    farray[0](original, str1);
}

int original(int c)
{
    return c;
}

//print STR in FPOINT type, STR is not changed,
void show(int (*fpoint) (int), char *str)
{
    int len;
    len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        putchar(fpoint(str[i]));
    }    

    putchar('\n');
}


//change STR to FPOINT type, and print STR, 
void change(int (*fpoint) (int), char *str)
{
    int len;
    len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        str[i] = fpoint(str[i]);
    }
    puts(str);
}
