#include <stdio.h>
//gcc -m32 -masm=intel -S -fverbose-asm main.c
//-m32 生成32位的代码
//-S   生成汇编代码
//-fverbose-asm 将C代码作为备注显示在汇编代码中


//gcc -m32 -g -o main main.c
//objdump --source main.exe >main.dump
//先生成可执行文件（windows会自动加上exe后缀）
//再通过objdump反编译为机器码


void assign(){
    int arr[3]={1,2,3};
    int *p;
    int i=5;
    int j=10;
    i=arr[2];
    p=arr;
    printf("i=%d\n", i);
}

void control(){
    int i=5;
    int j=10;
    if(i<j){
        printf("i is small\n");
    }
    for (int k = 0; k < 5; ++k) {
        printf("This is loop\n");
    }
}

int add(int a, int b){
    int ret;
    ret=a+b;
    return ret;
}

int main() {
    int a,b,ret;
    int *p;
    a=5;
    p=&a;
    b=*p+2;
    ret=add(a,b);
    printf("add result = \n.", ret);

    return 0;
}
