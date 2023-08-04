#include <iostream>
#include <vector>

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


int main (void)
{
    int N;
    std::vector<int> PO{};
    char ch;
    
    while ((ch = getchar()) != '\n') 
    {
        ungetc(ch, stdin);
        if (N != 0)
        {
            std::cin >> N;
            PO.push_back(N);
        }
        else
        {break;}
    }
    

/**/    std::vector<int> DER;
    for (size_t i = 0; i < PO.size(); i = i+2)
    {
        DER.push_back(PO[i+1] * PO[i]);
        DER.push_back(PO[i+1] - 1);
    }
    
    DER.pop_back();
    DER.pop_back();
    printVec(DER);

    return 0;
}