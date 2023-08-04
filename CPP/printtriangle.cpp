#include <iostream>

/* use N symbol C to print two opposite(down and up) triangles(like a sand clock), */
void printtriangles (int N, char C)
{
    using namespace std;

/* 1. receive input number from main,  */ 
// use if to avoid other situations, 
    if (N < 1)
    {N = 1;}

/* 2. calculate lines need to print 
*     by calculating first line's number */

    int numberOffirst;
        //should return 1 for 1, 2-6; 3 for 7, 8-16; 5 for 17, 17-30; and so on,

    int i = 0;
        //should return 1 for 1, 2-6; 2 for 7, 8-16; 3 for 17, 17-30; and so on,

    while (2 * i * i - 1 <= N)
    {i++;}
    
    i = i - 1;
    numberOffirst = 2 * i - 1;

// check1    cout << numberOffirst << endl;

/* 3. print the first line */

    string allstar(numberOffirst, C);
    cout << allstar << endl;



/* 4. print middle lines */

// need to calculate the number of '*' and ' ', 
// use loop to print multi-lines

// print the down triangle
    for (int numberOfspace = 1; numberOfspace * 2 < numberOffirst; numberOfspace++)
    {
        int numberOfstar;
        numberOfstar = numberOffirst - 2 * numberOfspace;
        string spacesa(numberOfspace, ' ');
        string stars(numberOfstar, C);
        string spacesb(numberOfspace, ' ');

        cout << spacesa + stars << endl;
    }

// print the up triangle, change start number to 3 make it "more accurate",
    for (int numberOfstar = 1; numberOfstar < numberOffirst; numberOfstar = numberOfstar + 2)
    {
        int numberOfspace = (numberOffirst - numberOfstar) / 2;
        string spacesa(numberOfspace, ' ');
        string stars(numberOfstar, C);
        string spacesb(numberOfspace, ' ');

        cout << spacesa + stars << endl;
    }


/* 5. print the last line */
    if (N > 6)
    {cout << allstar << endl;}



/* 6. print remaining numbers */
    int remaining;
    remaining = N - 2 * i * i + 1;
    cout << remaining << endl;


}


int main (void)
{
    int N;
    char C;

    std::cin >> N >> C;

    printtriangles(N, C);

    return 0;
}