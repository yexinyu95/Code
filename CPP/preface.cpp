#include <iostream>
#include <vector>
#include <algorithm>

// a short example of library vector,
void vectorEx()
{
    std::vector<int> x{0, 1, 8, 13, 5, 2, 3};
    x[0] = 21;

    x.push_back(1);

    std::sort(x.begin(), x.end());

    for (auto number : x)
    {
        std::cout << number << " ";
    }
    
    std::cout << std::endl;
}

void lambdaEx()
{    
    [](auto number){return number % 2 == 0;};
}


// a brief example of template,
template <typename T>
T add(T x, T y, T z)
{return x + y + z;}


int main (void)
{
    auto a = add(1, 2, 3);

    return 0;
}
