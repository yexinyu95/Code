#include<stdio.h>

int main(void)
{
    int cubes;
    printf("the number to calculate cube:.\n");
    scanf("%d", &cubes);
    
    int i = 1;
    int cube;

    for(i = 1; i <= cubes; i++)
    {
        cube = i * i * i;
        printf("the cube of %d is %d.\n", i, cube);
    }

    // printf("the cube of %d is %d.\n", i, cube);

    return 0;
}