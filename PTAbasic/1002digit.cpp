#include<iostream>
#include<vector>

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

int main(void)
{
    using namespace std;

    string pinYin[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

    string inputNum;
    cin >> inputNum;

    vector<int> diGit = strnumberVector(inputNum);

/*  check 

    for (size_t i = 0; i != diGit.size() ; i++)
    {cout << diGit[i] << ' ';}

    cout << endl;
*/


    int summary = 0;
    for (size_t i = 0; i != diGit.size(); i++)
    {
        summary = summary + diGit[i];
                
    }
//  check    cout << summary << endl;    

/**/
    vector<int> reSult = numberVector(summary);

    for (size_t j = 0; j != reSult.size(); j++)
    {
        cout << pinYin[reSult[j]];
        if (j != reSult.size() - 1)
        {cout << ' ';}
    }
    cout << endl;

    return 0;
}
