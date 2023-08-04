#include <stdio.h>
#include <string.h>

int main (void)
{
    int   array1[100] = {1, 2, 3, 4, 5};
    char  array2[100] = "apple";
    float array3[100] = {1.2, 1.3, 1.4, 1.5, 1.6};
//  wrong usage, but not error usage,
//  memcpy(array1, array3, 5 * sizeof(float));

//  right usage,
    int   array4[100] = {1, 3, 5, 7, 9};
    memcpy(array1, array4, 5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        printf("%d.\n", array1[i]);
    }

    return 0;
}