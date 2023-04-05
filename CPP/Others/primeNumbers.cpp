#include <iostream>

/*receive an input integer n, return a boolean
 *about whether the integer is prime,*/
bool isPrime(int n)
{
    bool prime = false;
    int i = 2;
    while (i < n)
    {
        if ((n % i) == 0)
        {prime = true;}
        i++;
    }
    
    return (!prime);
}


/*choose prime numbers in given range N(less than 100000), 
 *return an array(pointer) of these numbers, */
int* primeArray (int N)
{
    //need to explicitly declared as "static",
    static int primeArray[10000];
    int j = 1;

    for(int i = 3; i < N; i++)
    {
        if (isPrime(i))
        {
            primeArray[j] = i;
        //  check the number,  std::cout << i << std::endl;
            j++;
        }
    }

    //check the amount,  std::cout << j << std::endl;

/*compute the difference

    int num = 0;

    for(int k = 1; k < j - 1; k++)
    {
        int difference = primeArray[k + 1] - primeArray[k];
        
        if(difference == 2)
        {num++;}
    }

    std::cout << num << std::endl;

*/

    return primeArray;
}

/*compute given number N's amount in given array,
 *return N's amount(integer)*/
int checkamount (int N, int numberarray[])
{
    int j = 0;
    for(int i = 1; i < 1000; i++)
    {
        if (N == numberarray[i])
        {j++;}
    }

    return j;
}

/*! "sizeof" on array "function parameter" 
 * will always return sizeof "int*"(8), 
 * so this function doesn't works, 
 * one way is to compute the length 
 * on the initialization of the array,*/

//    int LEN = sizeof(numarray) / sizeof(numarray[0]);


/*code for PTA questions, 
 *correct but exceed required time limit*/
int checkDifference(int N)
{
    int i = 3;
    int result = 0;

    int num1, num2 = 0;

    while (i < N)
    {       
        if(isPrime(i))
        {num1 = i;}
        i++;

        while(!isPrime(i))
        {i++;}
        num2 = i;

        int difference = num2 - num1;
        if(difference == 2)
        {result++;}
    }

    return result;
}

int main(void)
{
//  receive an input number,
    int N;
//    std::cin >> N; 

//  the pointer need to assign to a int* variable, not an array, 

    int *arr;
    arr = primeArray(N);

    std::cout << arr[10] << std::endl;

    return 0;
}