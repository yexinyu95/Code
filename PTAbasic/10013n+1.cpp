#include<iostream>

using namespace std;

int main(void)
{
    int inputNum;
    cin >> inputNum;
    
    int divTimes = 0;
    
    while (inputNum != 1)
    {
        if (inputNum % 2 == 0)
        //use remain division to check whether inputNum is even,
        {inputNum = inputNum / 2;}
        
        else
        {
            inputNum = 3 * inputNum + 1;
            inputNum = inputNum / 2;
        }
        divTimes++;
        
    }
    
    cout << divTimes << endl;
}