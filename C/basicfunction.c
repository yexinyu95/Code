#include <stdio.h>
//function prototype
void printstar(void);
void printgivenchar(char ch, int num);
int minimum(int n, int m);

int main(void)
{
    printf("%d is less. \n", minimum(3.0, 5.0));

    return 0;
}

//no input, no output(return)

void printstar(void)
{
    int count;
    const int WIDTH = 30;

    for (count = 1; count <= WIDTH; count++)
    {putchar('*');}

    putchar('\n');

    return;

    printf("Statement after return will not be printed. \n");
}

//two input, no output(return)
void printgivenchar(char ch, int num)
{
    int count;
    for (count = 1; count <= num; count++)
    {putchar(ch);}

    putchar('\n');
}

//two input, one output
int minimum(int n, int m)
{
/*  printf("Input two numbers: \n");
    scanf("%d, %d", &n, &m);
*/

    int min;

    if (n < m)
        {min = n;}
    else
        {min = m;}

    return min;
}
