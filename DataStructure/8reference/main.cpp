#include <stdio.h>


void modify_num(int &b){ //形参中的&称为引用
    b = b + 1;
}

//数据结构要大量的用到指针, 因此修改指针的函数非常重要
void modify_pointer(int *&p, int *q){

}



int main() {
    int a = 10;
    modify_num(a);
//    printf("a = %d.\n", a);

    int *p = NULL;
    int i = 10;
    int *q = &i;
    modify_pointer(p, q);

    printf("after modify_pointer *p = %d.\n", *p);
    //进程结束后, 若退出代码不为0, 则说明程序异常退出
    return 0;
}
