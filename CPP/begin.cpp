
#include <iostream>

#include <cstdio>
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
    Cprint();
    CPPprint();
    
    return 0;
}