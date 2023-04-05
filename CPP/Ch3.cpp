#include <iostream>

void pointEx()
{
    int numa = 12;
    int* p = &numa;
    int numb = 13;

//  p now POINT to numb,
    p = &numb;
    printf("%d.\n", numa);
    printf("%d.\n", numb); 
    printf("%d.\n", *p);
    
    int valuea = 100;
    int& r = valuea;
    int valueb = 200;
    
/*
 *r still BIND with valuea, 
 *that statement CHANGE valuea to 200, 
 *instead of BIND r with valueb,
 */
    r = valueb;  

    printf("%d.\n", valuea);
    printf("%d.\n", valueb);
    printf("%d.\n", r);

}

void constEx()
{
    const int numa = 123;
    auto r1 = &numa;

//    r1 = 123;
    printf("%d.\n", numa);
//    printf("%d.\n", r1);

//  const methods,
    class Clock
    {
        int getyear() const
        {return year;}

        int year = 0;
    };

}

struct ACout
{
    const char* name;
    static long apert;
};

int main (void)
{
//    ACout::name;
    int* num = new int{42};

    return 0;
}