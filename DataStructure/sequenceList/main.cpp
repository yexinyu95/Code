#include <cstdio>
#include <cstdlib>
#define MaxSize 50


//专门用于定义数组中的元素, 以后修改起来更为方便
typedef int ElemType;

//顺序表结构的定义
typedef struct{
    ElemType data[MaxSize];  //初始化, 申请的空间为最大值
    int len;            //用于记录最终插入的数据个数
} SqList;

typedef struct{
    ElemType *data;      //理论上, 也可以使用指针动态分配内存, 但对于顺序表, 这种方式并不常见
                    //使用前, 需要使用malloc先分配内存
    int capacity, length;     //这样声明的数组同样是顺序存储结构
}pSqList;


//顺序表的元素插入, 因为需要改变L, 所以需要声明为引用类型
bool ListInsert(SqList &L, int pos, ElemType element){
    //判断插入位置是否合法(1<= pos <= L.len时合法)
    if(pos > L.len or pos<1 ){
        return false;
    }
    if(L.len == MaxSize){
        return false;
    }
    //元素集体右移
    for (int i = L.len; i >= pos; i--) {
        L.data[i] = L.data[i-1];
    }
    //插入元素
    L.data[pos-1] = element;
    //更新顺序表的长度
    L.len++;
    return true;
}

//顺序表的元素删除, 此处的"删除"为用新的元素覆盖了旧的元素
bool ListDelete(SqList &L, int pos, ElemType &del){
    //判断删除的元素位置是否合法
    if(pos > L.len or pos < 1){
        return false;
    }
    //取出删除的值, 但不作为函数的返回值返回
    del = L.data[pos-1];
    //元素集体左移
    for (int i = pos-1; i < L.len-1; ++i) {
        L.data[i] = L.data[i+1];
    }
    //更新顺序表的长度
    L.len--;
    return true;
}

//顺序表的元素查找, 不需要改变元素;存在元素则返回(第一个元素的)位置, 不存在则返回0
int LocateElem(SqList L, ElemType element){
    int i;
    for (i = 0; i < L.len; ++i) {
        if(element == L.data[i]){
            return i+1;//加1之后才是数组的下标
        }
    }
    return 0;
}

//顺序表的元素打印, 不需要改变元素, 所以直接调用参数
void PrintList(SqList S){
    for (int i = 0; i < S.len; ++i) {
        printf("%3d ",S.data[i]);
    }
    putchar('\n');
}



int main() {

//顺序表的初始化
    SqList L = {{1,2,3}, 3};
    int ret;
    //插入元素
    ret = ListInsert(L, 2, 60);
    if(ret){
        printf("Insert sqlist success.\n");
        PrintList(L);
    }
    else{
        printf("Insert sqlist failed.\n");
    }

    //删除元素
    ElemType del;
    ListDelete(L, 2, del);
    if(ret){
        printf("Delete successful, delete element = %d\n", del);
        PrintList(L);
    }
    else{
        printf("Delete failed.\n");
    }

    //查找元素
    ret = LocateElem(L, 2);
    if(ret){
        printf("locate element successful, location is %d.\n", ret);
    }
    else{
        printf("cannot locate element.\n");
    }


    return 0;
}
