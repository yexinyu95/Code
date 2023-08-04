#include <stdio.h>
#include <math.h>

int main (void)
{
    //initilalize numbers
    int row;
    int column;

    double num1;
    double num2;

    //receive inputs
    printf("input a number: ");
    scanf("%lf", &num1);

    printf("input row and column: ");
    scanf("%d %d", &row, &column);

    //print matrix
    for (int i = 1; i <= row; i++)
    {
        printf("%d ", 1);
        for(int j = 1; j < column; j++)
        {
            num2 = pow (num1, j);
            printf("%d ", (int)num2);
        }
        num1++;
        printf("\n");

    }

    return 0;

}
