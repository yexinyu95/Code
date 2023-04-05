#include <iostream>

using namespace std;

//initialize the pokeArray,
string pokeArray[60] = {"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", "J1", "J2"};


string* shuffling(string sArray[], int iArray[])
{
    static string resultPoke[60];
    for (size_t i = 0; i < 54; i++)         
    {
        for (size_t j = 0; iArray[j] != (i + 1); j++) // compare the index with loop,
        {
           resultPoke[i] = sArray[j];       // fill the new array,
        }
        
    }
    
    return resultPoke;
}

int main (void)
{
//receive one input as repeat times,
    int repeat;
    cin >> repeat;

//receive 54 input and store it in array,
    int orderArray[60];
    int i = 0;

    while (i < 54)
    {
        cin >> orderArray[i];
        i++;
    }

/*check the input     
    for (size_t j = 0; j < 54; j++)
    {
        cout << orderArray[j] << ' ';
    }
    
    cout << endl;
*/

//calling the function for repeat times,
    for (size_t i = 0; i < repeat; i++)
    {
        for (size_t j = 0; j < 54; j++)
        {
            pokeArray[j] = shuffling(pokeArray, orderArray)[j];
        }   
    }
    
    for (size_t j = 0; j < 54; j++)
    {
        cout << pokeArray[j] << ' ';
    }
    return 0;
}
