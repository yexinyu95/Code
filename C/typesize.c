#include <stdio.h>
#include <limits.h>
#include <float.h>


int main(void)
{
    printf("the size of char is %d bytes.\n", (int)sizeof(char));
    printf("the size of int is %d bytes.\n", (int)sizeof(int));
    printf("the size of unsigned int is %d bytes.\n", (int)sizeof(unsigned int));

    printf("the CHAR_MAX number is : %d\n", CHAR_MAX);
    printf("the INT_MAX number is : %d\n", INT_MAX);
    printf("the FLOAT_MAX number is : %f\n", FLT_MAX);

/*  other data types

    printf("the size of short is %zd bytes.\n", sizeof(short));
    printf("the size of long is %zd bytes.\n", sizeof(long));

    printf("the size of float is %zd bytes.\n", sizeof(float));
    printf("the size of double is %zd bytes.\n", sizeof(double));
    printf("the size of long double is %zd bytes.\n", sizeof(long double));
*/
    return 0;
}