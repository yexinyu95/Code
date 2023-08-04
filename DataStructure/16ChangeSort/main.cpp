#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXSIZE 50

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

void swap(int &a, int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}


//优先写内层循环
void BubbleSort(int *ar, int len){
    bool flag;
    for(int i=0;i<len-1;i++){//控制有序的数字的数目
        flag=false;
        for(int j=len-1;j>i;j--){//进行比较和交换
            if(ar[j]<ar[j-1]){
                swap(ar[j],ar[j-1]);
                flag=true;
            }
        }
        if(false==flag){//如果一轮比较后，没有发生任何交换，则说明数组已经有序
            return;
        }
    }
}
//快速排序的核心函数,采用“挖坑法”实现
int partition(ElemType *ar, int low, int high){
    //初始化轴点
    ElemType pivot=ar[low];
    while(low<high){
        //从后向前遍历，找到一个比分割值小的值（的下标）
        while(low<high&&ar[high]>=pivot)
            high--;
        ar[low]=ar[high];//交换

        //从前向后遍历，找到一个比分割值大的值（的下标）
        while(low<high&&ar[low]<=pivot)
            low++;
        ar[high]=ar[low];//交换
    }
    ar[low]=pivot;//最后将存储的轴点放回两个交换好的数组的中间

    //返回最后的中间值的下标
    return low;
}

void QuickSort(ElemType *ar, int low, int high){
    if(low<high) {
        //pivot用来存储分隔值的位置
        int pivot = partition(ar, low, high);

        //先递归到前半部分都排完
        QuickSort(ar, low, pivot-1);
        //再递归后半部分
        QuickSort(ar, pivot+1, high);
    }
}

int main() {
    SSTable ST;
    SSTable_Init(ST, 10);

    QuickSort(ST.data, 0, ST.len-1);
    SSTable_print(ST);


    return 0;
}
