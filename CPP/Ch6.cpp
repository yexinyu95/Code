#include <cstdio>


void constCast()
{
    int A = 12;
    const int* p = &A;
    printf("%d.\n", A);

    auto pt = const_cast<int*> (p);
    
    *pt = 13;
//    *p = 123;
    
    printf("%d.\n", A);
}





int main (void)
{



    return 0;
}