//comments write in one line

/*comments can also
  write in 
  multilines */

//include basic libraries
#include <iostream>
using namespace std;

//anatomy of a function
void printCPP (void)
{
// using 'cout' keyword and << operator to output,
// 'endl' is used to end message
// stdcout will auto change line
    std::cout << "Hello, C++," << std::endl;
}

void variable(void)
{
// variables are used to store value, also be seen as 'container',
// "camel Case naming" convention,

// variable need to 'explicitly' defined when the variable is created,
    int a; //declare a variable 
    a = 5; //initialize the value
           //variable(name) a cannot change its type once declared,

    char b = 'q';

// string s = "C++ do not has string variable."
}

double average(double a, double b)
{
    double sum = a + b;
    return sum / 2;
}

int controlflow(int a, int b)
{
// Boolean Expressions
// compare opeator and calculate opaetor
    int c;
    if (a < b)
    {
        c = a;
    }
//  'elif' is not defined
    else if (a = b)
    {    }
    
    else
    {
        c = b;
    }
//  "control reaches end of non-void function"
    return c;
}

void loops(int a, int b)

{
    while (a < b)
    {
        a = a + 1;
        cout << a <<endl;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << i <<endl;
    }
    
    
}

int main (void)
{
    int myValue = 2;
    cout << "myValue: " << myValue << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << i <<endl;
    }

    return 0;
}


