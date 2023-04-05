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

constexpr int scale(int cnt) 
    {return 42 * cnt;}


int main (void)
{
    using namespace std;

    string str = "hello, world.";
    typedef decltype(shorterString) *Func;
    using PF = decltype(shorterString);

    int DB = 3;
    int ar[2] = {0, 1};


    
    DB = 5;
//    cout << (123 / 1000) << endl;

    

    return 0;
}