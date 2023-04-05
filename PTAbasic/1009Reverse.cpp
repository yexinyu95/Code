#include <iostream>
#include <vector>

void printVec (std::vector<std::string> VEC)
{
    for (size_t i = VEC.size()-1; i != -1; i--)
    {
    std::cout << VEC[i];
    if (i != 0)
    {std::cout << ' ';}
    }
    
    std::cout << std::endl;
}

std::vector<std::string> inputEOF ()
{
    std::vector<std::string> RE{};

    std::string temp;
    while (std::cin >> temp)
    {
        RE.push_back(temp);
    }
    
    return RE;
}

int main (void)
{
    std::vector<std::string> STR;

    std::string temp;
    char ch;
    while ((ch = getchar()) != '\n')
    {
        ungetc(ch, stdin);
        std::cin >> temp;
        STR.push_back(temp);
    }

    printVec(STR);

    return 0;

}