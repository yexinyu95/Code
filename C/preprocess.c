#include <stdio.h>

//define variable
#define PI 3.14159
#define var1 2 + 2
#define STR1 "Sentence can write\
 in two line with backslash.\n"

//define 'function'
#define SUM(X, Y) (X + Y)
#define ABS(X)    ((X) < 0 ? -(X) : (X))

//error
#if __STDC_VERSION__ != 201710L
#error NOT C17

#endif

//pragma
#pragma C9X on

int main (void)
{
    printf("%d.\n", var1 * 2);
    puts(STR1);

    printf("%d.\n", 3 * SUM(2, 3));
    printf("%d.\n", ABS(-11));

    printf("The file is %s.\n", __FILE__);
    printf("The date is %s.\n", __DATE__);
    printf("This is line %d.\n", __LINE__);

    return 0;
}
