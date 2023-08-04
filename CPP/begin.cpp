#include <iostream>
#include <cstdio>

#include <cfloat>
#include <climits>

#define ABS(X) (X>0)?(X):-(X)

/* same as 
#include "stdio.h"
*/

void Cprint (void)
{
/*  C syntax is still supported, */

    printf("A C code output.\n");
}

void CPPprint (void)
{
    std::cout << "Hello, C++," << std::endl;

/*  another output grammar */

    using namespace std;
    cout << "Hello, g++,";
    cout << endl;
}




int main()
{    
    float f1=16777555.0f;
    f1+=20;
    printf("%f\n", f1);

    int i = 123456789;
    float f2 = (float)i;
    printf("%f\n", f2);

    float f3=0.33f;
    float f4=0.11f;
    f4+=0.22f;

    if(f3!=f4)
        printf("Not Equal.\n");
    if(ABS(f3-f4)<FLT_EPSILON)
        printf("Equal.\n");
    
    int   num1=0x42150000;
    float num2=22.78125f;

    printf("num1=0x%x, mean      %f   in IEEE754.\n", num1, *((float*)&num1));
    printf("num1=%f ,  stored as 0x%x in IEEE754.\n", num2, *((int*)&num2));
    
    return 0;
}