#include <iostream>
#include <vector>

/*a basic exponential function for C++,
  return NUM ** EXP, and EXP should be postive integer,*/
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

/*print each element of given vector VEC,*/
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

/*check whether NUM in given vector VEC,*/
bool checkNUM (int N, std::vector<int> VEC)
{
    bool BL = false;

    for (size_t i = 0; i < VEC.size(); i++)
    {
        if (N == VEC[i])
        {BL = true; break;}
    }
    
    return BL;
}

/*compute given number N's amount in given vector VEC,
 *return N's amount(integer)*/
int checkamount (int N, std::vector<int> VEC)
{
    int j = 0;
    for(int i = 0; i < VEC.size(); i++)
    {
        if (N == VEC[i])
        {j++;}
    }

    return j;
}

/*receive multiple integer inputs, return the vector 
  store those integer, the number of integers is "LEN",*/
std::vector<int> vectorInput (int LEN)
{
//use with / std::vector<int> inPut = vectorInput(length);

    std::vector<int> inPut;

    int index = 0;
    while (index < LEN)
    {
        int temp;
        std::cin >> temp;
        inPut.push_back(temp);
        index++;
    }
    return inPut;
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
//check    cout << num << ' ' << endl;
    }
    
    return intVec;

/*check 
    for (size_t i = 0; numberVector(123793134)[i] != 0; i++)
    {cout << numberVector(123793134)[i] << ' ';}

    cout << endl;
*/ 
}

/*split the input string number "num" to a vector of each digit,
  return the vector, */
std::vector<int> strnumberVector (std::string num)
{
    std::vector<int> intVec;

    for (size_t i = 0; i < num.size(); i++)
    {
        int digit;
        digit = (int) num[i];
        digit = digit - 48;
        intVec.push_back(digit);
    }

    return intVec;

/*check 
    for (size_t i = 0; strnumberVector("123793134")[i] != 0; i++)
    {cout << strnumberVector("123793134")[i] << ' ';}

    cout << endl;
*/ 
}

/*combine multiple numbers in the vector NUM to a whole number,
  number start from index START(index start from 0), 
  and length is LEN(should less than NUM.size()),
*/
long combineNumber (int START, int LEN, std::vector<int> NUM)
{
    if (START + LEN > NUM.size() || START < 0)
    {return 0;}

    else
    {
        long number = 0;

        int i = 0;
        int factor = expo(10, LEN - 1);

        while (i < LEN)
        {
            number = number + (NUM[START + i] * factor);
            factor = factor / 10;
            i++;
        }

        return number;
    }
/*check
    std::vector<int> TEST = {1, 2, 3, 4, 2, 3, 5, 6};

    long temp = combineNumber(2, 3, TEST);

    std::cout << temp << std::endl;
*/
}




int main (void)
{
    return 0;
}