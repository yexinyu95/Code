#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <iostream>

void sizeOftype()
{
//  size of integers,
    int A = sizeof(int);
    int B = sizeof(int64_t);
    int C = sizeof(__int128);

//  size of floats,
    int F = sizeof(float);
    int G = sizeof(double);
    int H = sizeof(long double);

//  size of chars,
    int X = sizeof(signed char);
    int Y = sizeof(char16_t);
    size_t Z = sizeof("CPP");

// literal values,

// hexadecimal input prefix '0x',
    __int64_t  numa = 123456UL;

//    printf("%ld.\n", numa);

    __int128_t numb = 12345'67890'12345'67890;
/*  
 *not widely used, so these output statement either works,
 *printf("%lu.\n", numb);
 *std::cout << numb << std::endl;
*/

    long double numc = 12345'67890'12345'67890;
    double numd = 3e-1;

//    printf("%lf.\n", numd);

//  other chars,
    char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";
    for (auto &&i : chinese)
    {
        std::cout << i << '\n'; //don't works, 
    }
    

//  sizeof operator
    std::string arr[] = {"APP", "BPP", "CPP"};

    constexpr size_t L = sizeof(arr) / sizeof(*arr);

    printf("%ld.\n", L);
}


void selfDeftype()
{
    enum class Color
    {Red, Green = 3, Blue};

    auto CO = Color::Green;
    
    union student{char name[10]; float height, weight;};

    student A;

    auto ST = A.height;
}


void classEx()
{
    struct student
    {
//constructor,

    student()          
    {puts("no argument.\n");}

    student(double x)  //overload is valid,
    {printf("weight : %lf"), x;}

//destuctor,
    ~student()
    {}

//    private:
        double weight = 65.0;
        std::string name = "TOM";
        

    public:
        void printName()
        {printf("%s.\n"), name;}
    };

//    student::student()          //fully qualified constructor call is not allowed,
//    {puts("no argument.\n");}


    class graduate
    {
//    private:
        double weight = 65.0;
        double height = 170.0;

    public:
        double BMI(double height, double weight)
        {printf("%lf.\n", (weight / height / height));}
    };

    
//    Ch2::~Ch2()
    {
    }

    student  A;
    graduate B;

//    A.name;
//    B.weight;
}

void assignMent()
{
    int b{};
    int c();
    int d = {2};
}

int main (void)
{
    return 0;
}