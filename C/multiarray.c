#include<stdio.h>

void sumrows(int ar[][4], int rows);
void sumcols(int ar[][4], int rows);
int sum2d(int ar[][4], int rows);

int main(void)
{
    int array1[3][4] = {
        {2, 4, 6, 8},
        {3, 5, 7, 9},
        {12, 10, 8, 6}
    };

    sumrows(array1, 3);
    sumcols(array1, 3);

    printf("Sum of all is %d. \n", sum2d(array1, 3));

    return 0;
}

void sumrows(int ar[][4], int rows)
{
    int r;
    int c;
    int total;

    for(r = 0; r < rows; r++)
    {
        total = 0;
        for(c = 0; c < 4; c++)
        {total = total + ar[r][c];}

        printf("row %d :sum = %d \n", r, total);
    }
}

void sumcols(int ar[][4], int rows)
{
    int r;
    int c;
    int total;

    for(c = 0; c < 4; c++)
    {
        total = 0;
        for(r = 0; r < rows; r++)
        {total = total + ar[r][c];}

        printf("col %d :sum = %d \n", c, total);
    }
}

int sum2d(int ar[][4], int rows)
{
    int r;
    int c;
    int total = 0;

    for(r = 0; r < rows; r++)
    {
        for(c = 0; c < 4; c++)
        {total = total + ar[r][c];}
    }

    return total;
}