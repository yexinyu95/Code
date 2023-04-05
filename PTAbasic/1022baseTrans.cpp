#include <iostream>
#include <vector>

long expo (long NUM, int EXP)
{
    if ((typeid(EXP).name() == typeid(long).name()) && (EXP > 0))
    {
        long number = 1;
        for (size_t i = 0; i < EXP; i++)
        {number = number * NUM;}

        return number;
    }
    
    else
    {return 0;}
}

long fromdecimal(long NUM, int base)
{
    if (base > 10 and base != 16)
    {return NUM;}

    else
    {
        int i = 1;
        while (NUM - expo(base, i) > 0) 
        {i++;}
        i = i - 1;

        long result = 0;
        long temp;
        while (i >= 0)
        {
            temp = NUM / (expo(base, i));
            result = result + temp * (expo(10, i));
            NUM = NUM - temp * (expo(base, i));
            i = i - 1;
        }
        return result;
    }
}


int main (void)
{
    long N;
    std::cin >> N;

    long res = fromdecimal(N, 8);

    std::cout << res <<std::endl;
}