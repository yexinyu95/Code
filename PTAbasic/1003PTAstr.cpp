#include <iostream>
#include <vector>
std::vector<std::string> vectorInput (int LEN)
{
//use with / std::vector<int> inPut = vectorInput(length);

    std::vector<std::string> inPut;

    int index = 0;
    while (index < LEN)
    {
        std::string temp;
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

    int N;
    cin >> N;

    std::vector<string> inPut = vectorInput(N);

    for (size_t i = 0; i != inPut.size() ; i++)
    {
        if (inPut[i] == "PAT" || inPut[i] == "PATA" || inPut[i] == "APAT" || inPut[i] == "APATA" )
        {cout << "YES" << '\n';}
        else
        {cout << "NO"  << '\n';}
    }

    cout << endl;

    return 0;
}