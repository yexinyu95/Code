#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++) //only check to sqrt(n) will save time,
    {
        if (n % i == 0)
        {return false;} //return will end the function, 
    }
    return true;
}

vector<int> primeVec (int M, long N)
{
    vector<int> primeV{};

    if (M > N)
    {return primeV;}

    else
    {    for(long i = M; i <= N; i++)
        {
            if (isPrime(i))
            {primeV.push_back(i);}
        }
    //check std::cout << j << std::endl;

        return primeV;
    }
}

void printVec (std::vector<int> VEC, int START, int END)
{
    int output = 0;
    for (size_t i = START - 1; i != END; i++) //index start from 0, so need to - 1,
    {
        std::cout << VEC[i];
        output++;
        if (output == (END-START+1))
        {;}
        else if ((output % 10) == 0)
        {putchar('\n');}
        else
        {putchar(' ');}
        
    }
    putchar('\n');
}


int main (void)
{
    int M, N;
    cin >> M >> N;

    vector<int> CP1 = primeVec(2, 110000);

    printVec(CP1, M, N);

    return 0;
}