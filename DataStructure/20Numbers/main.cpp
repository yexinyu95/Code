#include <cstdio>
#include <climits>
#include <cfloat>
#define ABS(X) (X>0)?(X):-(X)

void integer(){
    int i,j,k;
    i=-5;
    size_t L1=sizeof(long);
    size_t L2=sizeof(long long);

    unsigned short s1=USHRT_MAX;
    unsigned int i1=UINT_MAX;
    int i2=INT_MAX;
    long l=LONG_MAX;

}

void floating (){
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

    int   num1=0x00000001;
    printf("num1=0x%x, mean      %e   in IEEE754.\n", num1, *((float*)&num1));

    float num2=22.78125f;
    printf("num2=%f ,  stored as 0x%x in IEEE754.\n", num2, *((int*)&num2));

    float f5=FLT_MIN;
    float f6=f5+1;
    printf("f6=%f", f6);

}




int main() {
    int   num1=0x7F800000;
    printf("num1=0x%x, mean      %e   in IEEE754.\n", num1, *((float*)&num1));

    return 0;
}
