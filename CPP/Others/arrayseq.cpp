#include <iostream>
#include <vector>

/*receive multiple integer inputs, return the vector 
  store those integer, the number of integers is LEN,*/
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

/*  check
    std::cout << LEN << '\n';

    for (size_t i = 0; i != inPut.size() ; i++)
    {std::cout << inPut[i] << ' ';}

    std::cout << std::endl;
*/
    return inPut;
}

int main (void)
{
    using namespace std;

    int length, shift;
    cin >> length >> shift;

    while (shift > length)
    {shift = shift - length;}
    

    std::vector<int> inPut = vectorInput(length);

    for (size_t i = (length - shift); i != inPut.size() ; i++)
    {cout << inPut[i] << ' ';}

    for (size_t j = 0; j != (length - shift) ; j++)
    {
        cout << inPut[j];
        if (j < (length - shift))
        {cout << ' ';}
    }

    cout << endl;
    
    return 0;
}