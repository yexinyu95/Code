#include <bits/stdc++.h>

using namespace std;

// check whether STR is correct,
bool check (string STR)
{
//first, check 'P', 'T', 'A's number,
    int pcount = 0, tcount = 0;

    //use range for to loop STR's char,
    for (auto c : STR)
    {
        if (c == 'P')
        {pcount++;
            /*
            if(tcount)  {return false;} 
            *if already find 'T' appears before 'P', then STR is incorrect,
            *this statement is optional, 
            */ 
        }
        else if (c == 'T')
        {tcount++;}

        else if (c != 'A')
        {return false;}
    }
    if (pcount != 1 || tcount != 1)
    {return false;}

//second, check 'P', 'T's location,
    int p = STR.find('P');
    int t = STR.find('T');
    if (t - p - 1 == 0) //amount of 'A' between 'P' and 'T' can only be 1,
    {return false;}

//third, check standard 3,
    int left = p;
    int mid = t - p - 1;
    int right = STR.size() - 1 - t;

    if (right != left * mid)
    {return false;}

    return true;
}

int main (void)
{
    //receive input string's amount,
    int NUM;
    cin >> NUM;

    //use loop to receive multiple inputs,
    while (NUM--)
    {
        string s;
        cin >> s;

        if(check(s))
        {puts("YES");}

        else
        {puts("NO");}
    }
    
    return 0;
}
