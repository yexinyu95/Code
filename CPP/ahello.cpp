#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

/*receive varying amount of numbers and print their sum,
  TYPE is used for testing other parameter, 
*/
void numSum(std::string TYPE, std::vector<double> lt)
{
    double sum = 0;

    for (auto beg = lt.begin(); beg != lt.end(); ++beg)
    {sum = sum + *beg;}
    

    std::cout << "The sum of " << lt.size() << " " << TYPE << " is " << sum << std::endl;
//  test : numSum("integer", {1, 2, 4}); 
//         numSum("double", {1.22, 2.29, 4.67});

}

const std::string &shorterString(const std::string &s1, const std::string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

std::vector<std::string> process()
{
    return{"app", "bpp", "cpp"};
}

std::string (*pf) (const std::string &, const std::string &);

constexpr int isqrt(int n)
{
    int i = 1;
    while (i * i < n)
    {++i;}
    
    return i - (i*i != n);
}


int main (void)
{
    using namespace std;
    constexpr int x = isqrt(14556);

    cout << x << endl;

    return 0;
}