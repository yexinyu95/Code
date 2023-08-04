#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> threeN (int NUM)
{
    vector<int> TNP{};

    while (NUM != 1)
    {
        if (NUM % 2 == 0)
        //use remain division to check whether NUM is even,
        {
            NUM = NUM / 2;
            TNP.push_back(NUM);
        }
        
        else
        {
            NUM = 3 * NUM + 1;
            NUM = NUM / 2;
            TNP.push_back(NUM);
        }        
    }

    return TNP;
}

void printVec (std::vector<int> VEC)
{
    for (size_t i = 0; i != VEC.size() ; i++)
    {std::cout << VEC[i] << ' ';}
    std::cout << std::endl;
}

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


int main (void)
{
/**/    int N;
    cin >> N;
    //receive the input number and store in TN,
    vector<int> TN = vectorInput(N);

    for (size_t i = 0; i < TN.size(); i++)
    {
        if (TN[i] != 0) //first check whether i is 0,
        {
            //make i's 3n+1 vector,
            vector<int> TEMP = threeN(TN[i]);
            
            //find whether other numbers in that vector, if in then remove the number,
            for (size_t j = 0; j < TN.size(); j++)
            {
                if(checkNUM(TN[j], TEMP))
                {TN[j] = 0;}
            }
        }
    }
    sort(TN.begin(), TN.end());

//    printVec(TN);

/**/    

    auto k = TN.size() - 1;

    while (TN[k] != 0)
    {
        
        cout << TN[k];
        if (TN[k-1] != 0)
        {cout << ' ';}
        k--;
    }


//    printVec(threeN(7));

    return 0;
}