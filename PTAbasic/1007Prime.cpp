#include <iostream>
#include <vector>

using namespace std;

/*receive an input integer n, return a boolean
 *about whether the integer is prime,*/
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++) //only check to sqrt(n) will save time,
    {
        if (n % i == 0)
        {return false;} //return will end the function, 
    }


    return true;
}

/*choose prime numbers in given range N, 
 *return an vector of these numbers, */
vector<int> primeVec (int N)
{
    vector<int> primeV{};

    for(int i = 2; i <= N; i++)
    {
        if (isPrime(i))
        {primeV.push_back(i);}
    }
    //check std::cout << j << std::endl;

    return primeV;
}


void printVec (std::vector<int> VEC)
{
    for (size_t i = 0; i != VEC.size(); i++)
    {
    std::cout << VEC[i];
    if (i != VEC.size() - 1)
    {std::cout << ' ';}
    }
    
    std::cout << std::endl;
}


int main(void)
{
//  receive an input number,
    int N;
    std::cin >> N;

    std::vector<int> PV = primeVec(N);

    /*check the difference*/
    int num = 0;

    for(int k = 1; k < PV.size(); k++)
    {
        int difference = PV[k] - PV[k-1];
        
        if(difference == 2)
        {num++;}
    }
    std::cout << num << std::endl;

    return 0;
}