#include <iostream>
#include <vector>

using namespace std;

void printVec (std::vector<char> VEC)
{
    for (size_t i = 0; i != VEC.size(); i++)
    {
    std::cout << VEC[i];
    if (i != VEC.size() - 1)
    {putchar(' ');}
    }
    
    std::cout << std::endl;
}


/*compare same index's char in given string A and B,
 *return a vector contain all same chars,
*/
vector<char> sameChar (string A, string B)
{
    //make sure the length won't overflow,
    long LEN;
    if (A.size() > B.size())
    {LEN = B.size();}
    else
    {LEN = A.size();}

    //initialize the vector,
    vector<char> CH;

    //save the loop's starting location ,
    int i = 0;

    //use for loop to compare each char, 
    for (; i < LEN; i++)
    {
        if (A[i] == B[i])
        {
            char m = A[i];
            int  t = (int)m;
//check            cout << t << '\n';
            //add the first uppercase char in this loop,
            if ((t >= 65 && t <= 90))
            {
                CH.push_back(m);
                break;
            }
        }
    }
    i++;

    for (; i < LEN; i++)
    {
        if (A[i] == B[i])
        {
            char m = A[i];
            int  t = (int)m;
//check            cout << t << '\n';
            //add the second char in this loop, might be uppercase or number,
            if ((t >= 65 && t <= 90) || (t >= 49 && t<= 57))
            {
                CH.push_back(m);
                break;
            }
        }
    }
    return CH;
}

int sameCharlocation (string A, string B)
{
    //make sure the length won't overflow,
    long LEN;
    if (A.size() > B.size())
    {LEN = B.size();}
    else
    {LEN = A.size();}

    //loop to find the index,
    for (size_t i = 0; i < LEN; i++)
    {
        if (A[i] == B[i])
        {
            char m = A[i];
            int  t = (int)m;
//check            cout << t << '\n';
            //char might be uppercase or lowercase,
            if ((t >= 65 && t <= 90) || (t >= 97 && t<= 122))
            {return i;}
        }
    }
    
    return 0;
}

int main (void)
{
    string STRa, STRb;
    cin >> STRa >> STRb;

    vector<char> TEMP = sameChar(STRa, STRb);

    int index3 = sameCharlocation(STRa, STRb);



    return 0;
}