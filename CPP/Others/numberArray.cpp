#include <iostream>
#include <vector>
#include <algorithm>

/*split the input long integer "num" to an array of each digit,
  return the array(pointer), */
int* numberArray (long num)
{
    static int NA[30];
    long division = 10;

    int index = 0;

    while ((num / division) != 0)
    {division = division * 10;}
//check    std::cout << division << std::endl;

    division = division / 10;
    while (division > 0)
    {
        NA[index] = num / division;
        num = num - (division * NA[index]);
        division = division / 10;
//check        std::cout << num << ' ' << std::endl;
        index++;
    }
    
/*check 
    for (size_t i = 0; numberArray(123793134)[i] != 0; i++)
    {
        std::cout << numberArray(123793134)[i] << ' ';
        
    }
    std::cout << std::endl;
*/ 
    return NA;
}

/*split the input long integer "num" to a vector of each digit,
  return the vector, */
std::vector<int> numberVector (long num)
{
    std::vector<int> intVec;

    long division = 10;
    while ((num / division) != 0)
    {division = division * 10;}
//check    std::cout << division << std::endl;

    division = division / 10;
    int digit = 0;

    while (division > 0)
    {
        digit = num / division;
        intVec.push_back(digit);
        num = num - (division * digit);
        division = division / 10;
//check        std::cout << num << ' ' << std::endl;
    }
    
    return intVec;

/*check 
    for (size_t i = 0; numberVector(123793134)[i] != 0; i++)
    {
        std::cout << numberVector(123793134)[i] << ' ';
        
    }
    std::cout << std::endl;
*/ 
}

int main (void)
{
    long input;
    
    std::cin >> input;

    std::vector<int> iveca = numberVector(input);

    std::vector<int> ivecb = numberVector(input * 2);

    std::sort(iveca.begin(), iveca.end());
    std::sort(ivecb.begin(), ivecb.end());

    if (iveca == ivecb)
    {std::cout << "Yes" << '\n';}
    else
    {std::cout << "No" << '\n';}

    std::cout << input * 2 <<  std::endl;

    return 0;

}