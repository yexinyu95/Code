#include <stdio.h>
#include <string.h>

void printarray(const float *ar, int n);

int main (void)
{
    union hold
    {
        int num1;
        float num2;
        char ch1;
    };

/*  one union varable 
    union hold fit = {'c'};
    
    putchar(fit.ch1);
    putchar('\n');

    //char c is "replaced" by 12,
    fit.num1 = 12;

    printf("%d.\n", fit.num1);
*/

/*  union array 
    union hold uarray1[10];

    uarray1[0].ch1 = 'c';
    uarray1[1].num1 = 12;
    uarray1[2].num2 = 12.12;

    printf("%p, %p, %p \n", uarray1, uarray1 + 1, uarray1 + 2);

    printf("%c, %d, %f \n", uarray1->ch1, uarray1[1].num1, uarray1[2].num2);
*/


/* array in union */
    union element
    {
        char ch1[10];
        float num1[10];
        float num2;
    };

    union element example = {"list"};

    puts(example.ch1);

/*  change elements to float number 
    example.num1[0] = 1.0;
    example.num1[1] = 1.1;
    example.num1[2] = 1.2;
    example.num1[3] = 1.3;

    printarray(example.num1, 4);

    example.num2 = 1.33;
    printf("%f.\n", example.num2);
*/

/*  union and array to make a simple list */
    union element list[10];
    strcpy(list[0].ch1, "Tom");
    
    list[1].num2 = 172.0;
    list[2].num2 = 60.0;

    printf("(\"%s\", %.2f, %.2f).\n", list[0].ch1, list[1].num2, list[2].num2);

    return 0;
}



/*  print an float array AR with list length N;
    change 'float' to 'int', change %f to %d to print int array;
    change 'float' to 'char', change %f to %c to print char array; */
void printarray(const float *ar, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%f, ", ar[i]);
    }
    putchar('\n');
}