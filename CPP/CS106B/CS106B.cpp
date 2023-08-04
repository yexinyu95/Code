#include <iostream>
#include <vector>

using namespace std;

//recursion

/*recursion has two main component : base case and recursive case
  recursive case might have different cases,
  it is helpful to think about 'back'-traking,
  it is helpful to use some variabl to record the recursion state,
  decision tree might be helpful to find the recursive case,

*/

void generateSequence(int length, string sofar)
{
    if (length == 0)
    {cout << sofar << endl;}

    else
    {
        generateSequence(length - 1, sofar + "H");
        generateSequence(length - 1, sofar + "T");
    }
}

void Permutation(string input, string sofar)
{
    
    if (input.empty())
    {cout << sofar << endl;}

    else
    {
        for (int i = 0; i < input.length(); i++)
        {
            char nextLetter = input[i];
            string rest = input.substr(0, i) + input.substr(i + 1);
            Permutation(rest, sofar + nextLetter);
        }
    }
}

//CPP class
/*
public: contain functions (simliar to methods) in the class, 
    define methods is similar to define functions,
    double colons :: is used to define the methods,
private: contain data and attributes, 

*/

class randomBag
{
private:
    vector<int> elems;

public:
};


int main (void)
{

    Permutation("valid", "");
    return 0;

}