#include <iostream>


int main (void)
{
    int i = 12;

    auto j = static_cast<double> (i);


    std::cout << typeid(i).name() << std::endl;

    return 0;
}