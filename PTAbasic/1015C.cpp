#include <cstdio>
#include <algorithm>

//define a struct to store data,
struct STU
{
    int id;
    int DE, CAI, sum;
    int group; //define extra parameter to classify student,
};

//define compare function, suppose students has already divided into groups,
bool cmp(STU a, STU b)
{
    if (a.group != b.group)
    {return (a.group < b.group);} //first compare group, 
    else if (a.sum != b.sum)
    {return (a.sum > b.sum);}
    else if (a.DE != b.DE)
    {return (a.DE > b.DE);}
    else
    {return (a.id < b.id);}
}


int main (void)
{
    int n, l, h;
    int unpass = 0;
    scanf("%d, %d, %d", &n, &l, &h);
    STU st[n];

    return 0;
}