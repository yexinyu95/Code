#include <iostream>
#include <vector>

using namespace std;

//use a struct to store node,
struct NUM
{
    string Address;
    long Data;
    long index = 0;
    string Next; 
}

// receive instructions in first line,
string START;
int total;
int rev;

cin >> START >> total >> rev;

// receive data and store,
NUM temp;

vector<NUM> LIST;
for (int i = 0; i < N; i++)
{
    cin >> temp.Address >> temp.Data >> temp.Next;
    LIST.push_back(temp);
}

// sort the list with address,
int INDEX = 1;

while (START != "-1")
{
    for (int i = 0; i < LIST.size(); i++)
    {
        if(LIST[i].Address == START)
        {
            LIST[i].index = INDEX;
            START = LIST[i].NEXT;
            break;
        }
    }
    INDEX++;
}

// calculate the output index with given length and reverse length,
vector<int> OUT;
int j = rev;
while (rev < total)
{
    for (int i = 0; i < j ; i++)
    {
        OUT.push_back(rev);
        rev--;
    }
    rev = rev + j + j;
}

rev = rev - j + 1;
while(rev != total)
{
    OUT.push_back(rev);
    rev++;
}


// print the struct with given sequence, add the location to each node,
if(LIST[i].index = OUT[0])
{
    cout << LIST[i].ADDRESS << ' ' << LIST[i].DATA;
}
if(LIST[i].index = OUT[1])
{
    cout << ' ' << LIST[i].ADDRESS;
}


int main (void)
{
    return 0;
}