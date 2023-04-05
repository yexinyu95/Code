#include <iostream>
#include <cctype>

using namespace std;

string complement (string dnaStrand)
{
//  use string to declare a string is legal,
    string backup = dnaStrand;
    
    for (int i = 0; i <= dnaStrand.length(); i++)
        if (toupper(dnaStrand[i]) == 'A')
        {
            backup[i] = 'T';
        }

        else if (toupper(dnaStrand[i]) == 'T')
        {
            backup[i] = 'A';
        }

        else if (toupper(dnaStrand[i]) == 'C')
        {
            backup[i] = 'G';
        }

        else
        {
            backup[i] = 'C';
        }

        return backup;

}

void CPPinput (void)
{
/*  input float or integer, seperate by space
    float num1, num2;
    cin >> num1 >> num2;

    cout << num1 + num2 << endl;
*/

/*  input char, seperate by space
    char ch1, ch2;
    cin >> ch1 >> ch2;
    cout << ch1 << ch2 << endl;
*/

/*  input string, receive char before space(not enter) */
    string str1;
    cin >> str1;
    cout << str1 << endl;

}

void Stringmethodb (void)
{
    string stra;
    stra.append("C");
    stra.append("P");
    stra.append("P");

    cout << stra << endl;

    stra.erase(2, 1);

    cout << stra << endl;

}

string reverseString (string stra)
{
    if (stra == "")
    {
        cout << "base" << endl;
        return "";
    }

    else
    {
        cout << "reverse" << endl;
        return reverseString(stra.substr(1)) + stra[0];
    }
}

void printCantor (int n)
{
    if (n == 1)
    {
        cout << "#.#" << endl; 
    }

    else
    {
        cout << '#' << "." * n << '#' << endl; 
    }
} 


int main (void)
{
    printCantor(3);

    return 0;
}