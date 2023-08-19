#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 50

//专门用于定义数组中的元素, 以后修改起来更为方便
typedef int ElemType;

//静态分配；即分配的空间确定后就不能更改
typedef struct SqList{
    ElemType data[MAXSIZE];  //初始化, 申请的空间为最大值
    int len;                 //用于记录最终插入的数据个数
} SqList;


//初始化顺序表，
void InitList(SqList &L){
    L.len=0;
    for (size_t i = 0; i < MAXSIZE; i++)
        L.data[i]=0;//设置默认值，理论上可以省略；因为顺序表的长度由len决定，
}


//顺序表的元素插入, 因为需要改变L, 所以需要声明为引用类型
bool ListInsert(SqList &L, int pos, ElemType element){
    //1. 判断插入位置是否合法，合法值应该为[1,len+1];还需要判断是否存满
    if(pos>L.len+1 || pos<1){
        return false;
    }

    if(L.len >= MAXSIZE){
        return false;
    }

    //2. 元素集体右移
    for (int i = L.len; i >= pos; i--) {
        L.data[i] = L.data[i-1];
    }

    //3. 插入元素
    L.data[pos-1] = element;

    //4. 更新顺序表的长度
    L.len++;
    return true;
}
/*
时间复杂度
最好：插入到表尾len+1，不需要移动元素，因此为O(1)
最坏：插入到表头1，需要移动所有元素，因此为O(n)
平均：假设插入到任何位置的概率均为1/(n+1)，循环次数为len-pos+1，
所以最后可以算得复杂度为O(n/2)=O(n)

*/


//顺序表的元素删除, 
//此处的"删除"实际上是用后边的元素逐个向前覆盖
bool ListDelete(SqList &L, int pos, ElemType &del){
    //1. 判断删除的元素位置是否合法
    if(pos > L.len or pos < 1){
        return false;
    }

    //2. 取出删除的值, 但不作为函数的返回值返回
    del = L.data[pos-1];

    //3. 元素集体左移
    for (int i = pos-1; i < L.len-1; ++i) {
        L.data[i] = L.data[i+1];
    }

    //4.更新顺序表的长度
    L.len--;
    return true;
}
/*
时间复杂度
类似元素插入，主要的操作都是元素的集体移动；所以时间复杂度相同

*/


//按位置查找元素，位置合理则返回对应的元素的值
//使用malloc动态分配的数组，同样可以使用下标来访问元素
int GetElem(SqList L, int pos){
    if(pos>=1 && pos<=L.len)
        return L.data[pos-1];//位置减1之后才是数组的下标
    return 0;
}
/*
时间复杂度：O(1)

*/


//按值查找元素，存在元素则返回(第一个元素的)位置, 不存在则返回0
int LocateElem(SqList L, ElemType element){
    int i;
    for (i = 0; i < L.len; ++i) {
        if(element == L.data[i]){
            return i+1;//加1之后才是数组的下标
        }
    }
    return 0;
}
/*
推广：`==`不能直接用于比较结构变量，需要依次对比结构的各个分量；
在C++中，可以通过重载运算符来实现比较，

*/

/*
时间复杂度
最好：查找的值在表头，因此为O(1)
最坏：查找的值在表尾，需要遍历到最后，因此为O(n)
平均：假设值在任何位置的概率均为1/n，对应循环次数为len-pos；
最后可以算得复杂度为O(n/2)=O(n)

*/



//顺序表的元素打印, 不需要改变元素, 所以直接调用参数
void ListPrint(SqList S){
    for (int i = 0; i < S.len; ++i) {
        printf("%5d", S.data[i]);
    }
    putchar('\n');
}



//动态分配
//可以使用指针动态分配内存, 但对于顺序表, 这种方式并不常见
typedef struct SeqList{
    ElemType *data;//指向顺序表的第一个元素，即数组的第一个元素
    int MaxSize;   //顺序表的最大容量
    int len;       //顺序表的当前长度
}SeqList;

//使用随机数初始化一个顺序表，长度为len
void InitList (SeqList &ST, int len){
    ST.data=(ElemType*)malloc(MAXSIZE*sizeof(ElemType));
    ST.len=0;
    ST.MaxSize=MAXSIZE;

    // srand(time(NULL));
    // for (int i = 0; i < MAXSIZE; ++i) {
    //     ST.data[i]=rand()%100;
    // }
}

/*
 * 增加顺序表的长度，
 * 实际上是重新分配了一部分空间，然后将原有的数据复制过去
 * 然后再free原来的空间
 */
void IncreaseSize(SeqList &L, int len){
    //1. 
    int *p=L.data;

    //2.
    L.data=(ElemType*)malloc((L.MaxSize+len)*sizeof(ElemType));
    
    //3.
    for (size_t i = 0; i < L.len; i++)
        L.data[i]=p[i];
    L.MaxSize=L.MaxSize+len;

    //4.
    free(p);
}

void SeqListprint(SeqList ST, int len){
    for (int i = 0; i < len; ++i) {
        printf("%5d", ST.data[i]);
    }
    putchar('\n');
}


int main() {

    return 0;
}
