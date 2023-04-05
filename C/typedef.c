#include <stdio.h>

int main (void)
{

/* define a complex number */ 
    typedef struct
    {
        float imag;
        float real;
    }
    COMPLEX;

    COMPLEX i;
    i.imag = 1;
    i.real = 0;

    printf("complex number i = %.1f + %.1f i.\n", i.real, i.imag);

    return 0;
}