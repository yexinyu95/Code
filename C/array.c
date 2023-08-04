#include<stdio.h>

void printarray(const int *ar, int n);
int sum (const int *ar, int n);
void increase (int ar[], int n);

int main (void)
{
/*  initialize array */
    int  array1[3] = {1, 3, 5};
    char array2[3];


/*  initialize and assignment 
    int array3[3] = {1, 2, 3};
    array3[2] = 4;
*/

/*  fill the array */

    array1[0] = 0;    
    array1[1] = 1;    
    array1[2] = 2;
    showarray(array1, 3);


/*  wrong fill statement 
//  extra (or wrong) assign won't make sense in numberarray
    array1[3] = 3;

    array2[0]   = 'a';
    array2[1]   = 'b';
    array2[2]   = 'c';
//  extra assign won't make sense in chararray 
    array2[37]   = 'd';

//  but wrong assign will cause 'stack smashing'
//  array[3]   = 'd';
*/

/*  initialize const arrays 
    const int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

//  const array can't be changed,
//    days[9] = 44;
*/

/*  initialize multidimensional arrays 
    int array4[2][3] = {{1, 2, 3}, {1, 2, 3}};

//  pointer
    printf("array is        pointer        : %p.\n", array4);
    printf("array[i] is     'child' pointer: %p.\n", array4[1]);
    printf("*(array + i) is 'child' pointer: %p.\n", *(array4 + 1));

//  element
    printf("array[i][j] is         variable: %d. \n", array4[1][1]);
    printf("*((*array + i) + j) is variable: %d. \n", *(*(array4 + 1) + 1));
*/

/*  initialize poniter for multidimensional arrays 
//    int *point4; will make mistake
    int (*point4)[3];
    point4 = array4;
    printf("array[i][j] is variable: %d. \n", (*point4)[2]);
*/

/*  use other functions 
    showarray(array3, 3);
    printf("The sum of array is %d. \n", sum(array3, 3));

    increse(array3, 3);
    showarray(array3, 3);
*/
    return 0;
}

/*  print an float array AR with list length N;
    change 'float' to 'int', change %f to %d to print int array;
    change 'float' to 'char', change %f to %c to print char array; */
void printarray(const int *ar, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", ar[i]);
    }
    putchar('\n');
}

// compute the summary of an array, with name and size 
int sum (const int *ar, int n) 
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total = total + ar[i];
//      will make mistake with const keyword,
//      *ar ++; 
    }

    return total;
}

//increase every element in the array, with name and size
void increase (int ar[], int n)
{
    for(int i = 0; i < n; i++)
    {ar[i] = ar[i] + 1;}
}






