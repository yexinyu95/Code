#include <cstdio>
#include <cstdlib>
#include <ctime>

typedef int ElemType;

typedef struct SSTable{
    ElemType *data;
    int len;
}SSTable;


//使用随机数初始化一个顺序表，长度为len
void SSTable_Init (SSTable &ST, int len){
    ST.len=len;
    ST.data=(ElemType*)calloc(len, sizeof(ElemType));

    srand(time(NULL));
    for (int i = 0; i < len; ++i) {
        ST.data[i]=rand()%100;
    }
}

void SSTable_print(SSTable ST){
    for (int i = 0; i < ST.len; ++i) {
        printf("%5d", ST.data[i]);
    }
    putchar('\n');
}

void InsertSort(ElemType A[], int n){
    int i,j,InsertVal;
    for(i=1;i<n;i++){//外层循环控制要插入的数据
        InsertVal=A[i]; //保存要插入的数据
        for(j=i-1;j>=0&&A[j]<InsertVal;j--){//内层控制比较
                A[j+1]=A[j];
        }
        A[j+1]=InsertVal;
    }
}


int main() {
    SSTable ST;
    SSTable_Init(ST, 10);
    SSTable_print(ST);

    int arr[10] = {1,4,5,1,3,3,9,2,7,8};

    InsertSort(ST.data, 10);
    SSTable_print(ST);

    return 0;
}
