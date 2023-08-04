#include <iostream>
#include <vector>

// use a "struct" to store different data type,
struct scoreName
{
    std::string name;
    std::string SN;
    int score;
};


int main (void)
{
    int NUM;
    std::cin >> NUM;
//  use array to store multiple structs, the dimension is given by problem,
    scoreName ar[NUM];

/*  use loop to store value to structs,
    seperated by input number(3),
*/
    for (size_t i = 0; i < NUM; i++)
    {std::cin >> ar[i].name >> ar[i].SN >> ar[i].score;}
    
/*  loop the struct to find the max and min,
    this test does NOT require SORTING, only need max and min,
    (use pointer seems not necessary,)
*/
    scoreName max = ar[0];
    scoreName min = ar[0];

    for (size_t j = 0; j < NUM; j++)
    {
        if (ar[j].score > max.score)
        {max = ar[j];}

        if (ar[j].score < min.score)
        {min = ar[j];}
    }
    
    std::cout << max.name << " " << max.SN << "\n";
    std::cout << min.name << " " << min.SN << std::endl;
    return 0;
}