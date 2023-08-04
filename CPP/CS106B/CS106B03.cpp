#include <iostream>

// C++'s string library
#include <cctype>
#include <string>


using namespace std;

void spaceship (void)
{
    for (int i = 10; i > 0; i--)
    {
        cout << i << endl;
    }

    cout << "Lifted up" << endl;
}


void letterloop(void)
{
//  loop could use with letter 
    for (char letter = 'a'; letter <= 'z'; letter++)
    {
        cout << letter << endl;
    }
}


void Cppstring (void)
{
//  tradition declartion of C string
    char worda[10] = "Hello";
    worda[1] = 'a';

    cout << worda <<endl;

//  C++ use typedef to include 'string' type,
    string wordb = "Hi";

}


void stringmethod (void)
{

    string wordc = "Hi";
    char letter = '!';

    cout << wordc <<endl;

//  string can use basic operator
    wordc = wordc + letter;

//  add string is illegal
//    string Hithere = "Hi" + "there";

//  add char is 'legal', but will not return true string,
//    string Hithere = "Hi" + '!';
//    cout << Hithere <<endl;


//  string's dot method
    for (int letterIndex = 0; letterIndex < wordc.length(); letterIndex++)
    {
        cout << wordc[letterIndex] <<endl;
    }

}


void removeLetters (string str)
{
    for (int i = 0; i < str.length(); i ++)
    {
        if (int(str[i]) > 58 || int(str[i]) < 47)
            {
                str[i] = ' ';
            }

    }

/*
    for (int i = 0; i < str.length(); i ++)
    {
        if (str[i] == ' ')
            {
                str.erase(i, 1);
            }
       
    }
*/

    cout << str << endl;
}



int main(void)
{
    removeLetters("L1Tcisd7d8fs87f6s8f6x7");

    return 0;
}