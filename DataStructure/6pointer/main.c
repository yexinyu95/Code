#include <stdio.h>
//在子函数内改变主函数中某个变量的值
void change(int i)
{
    i = 5;
}

void changepoint(int *j)
{
    *j = 5;
}

//指针与一维数组的传递
void pointarray(char *d){
    *d = 'H';
    d[1] = 'E';
    *(d+2) = 'L';
}


int main() {
    //int i = 10;
    //printf("%d\n",i);
    int a[] = {1,2,3,4,5};

    int *p;
    p = a+4;

    for(int i = 0; i < 5 ; i++)
    {
        //printf("%3d", *(p-i));
    }

    char c[10] = "hello";
    pointarray(c);
    puts(c);


    return 0;
}
