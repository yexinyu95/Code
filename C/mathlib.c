#include <stdio.h>

// require gcc mathlib.c -lm to compile
#include <math.h>

int main (void)
{
    double x = 9;
    double y = sqrt(x);

    double z = pow(y, 2);
    
    double a = fabs(-2.22);

    printf("z = %f.\n", z);

    return 0;
}