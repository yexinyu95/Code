#include <iostream>


/*by convention, "matrix" is an array of ROWs,
  for example, 
  1  2  1
  2  1  2
  1  1  3
  is  int M1[3][3] = {{1,2,1}, {2,1,2}, {1,1,3}};
*/

/*print a Matrix M with given ROW's, 
  colmun is limited to 3, 
  a basic function to use multidimensional array,
*/
void printMatrix (const int M[][3], size_t ROW)
{
    for(int r = 0; r < ROW; r++)
    {
        for(int c = 0; c < 3; c++)
        {
            std::cout << M[r][c] << " ";
        }
        std::cout << std::endl;
    }
}


int main (void)
{
    int M1[3][3] = {{1,2,1}, {2,1,2}, {1,1,3}};

    printMatrix(M1, 3);

    return 0;
}