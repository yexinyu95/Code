#include<stdio.h>
#include<math.h>

//gcc -o vandermonde vandermonde.c -lm

int main(void)
{
    //initialize numbers
    int  num1;
    double num2;

    int  row;
    int  column;

    //receive input
    printf("input an number: ");
    scanf("%d", &num1);

    printf("input row and column:");
    scanf("%d %d", &row, &column);


    //print first row
    for(int k = 1; k <= column; k++)
        printf("%d ", 1);
    printf("\n");

    //print other rows
    for (int i = 1; i < row; i++)
    {
        for(int j = 1; j <= column; j++)
        {
            num2 = pow((num1 + j), i);
            printf("%d ", (int)num2);
        }    
            
        printf("\n");
    }

    return 0;
}