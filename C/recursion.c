#include <stdio.h>

void exchange (int *u, int *v);
long factorial(int n);
int fibonacci(int n);
int iterfibonacci(int n);
int combinedefine (int r, int n);
int combine (int r, int n);


int main (void)
{
    int n;

    printf("Input the integer: \n");
    scanf("%d", &n);

    printf("fibonacci(%d) = %d \n", n, iterfibonacci(n));

    return 0;
}

void exchange (int *u, int *v)
{
    int temp;
    temp = *u;
    *u = *v;
    *v = temp;
}

int fibonacci(int n)
{   
    int fibo;

    if (n > 2)
    {fibo = fibonacci(n - 1) + fibonacci(n - 2);}

    else
    {fibo = 1;}

    return fibo;
}

int iterfibonacci(int n)
{
    if (n > 1)
    {
        int x = 0;
        int y = 1;
        int z;

        for (int i = 1; i < n; i++)
        {
            z = x + y;
            x = y;
            y = z;
        }
        return z;
    }
    else
    {return 1;}
}

long factorial(int n)
{
    long factor;

    if (n > 0)
        factor = n * factorial(n - 1);
    else
        factor = 1;
    
    return factor;
}

int combinedefine (int r, int n)
{
    int ans;

    ans = factorial(n) / (factorial(r) * factorial(n - r));
    return ans;
}

int combine (int r, int n)
{
    int ans;

    if (n > 1)
        if (r < n && r > 0)
        ans = combine(r, n - 1) + combine(r - 1, n - 1); 
        else
        ans = 1;
    else
    ans = 1;

    return ans;
}
