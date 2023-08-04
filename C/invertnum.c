#include<stdio.h>
//判断数字是否为对称数
int invert_num (int a)
{
    int b = 0;
    while(a)
    {
        b = b*10 + a%10;
        a = a/10;
    }

    return b;
}

int main (void)
{
    int a,b,backup_a;

    scanf("%d", &a);

    b = invert_num(a);

    printf("b = %d\n", b);
    return 0;
}