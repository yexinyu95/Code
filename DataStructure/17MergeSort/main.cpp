#include <cstdio>
#include <cstdlib>
#include <ctime>

#define N 7

typedef int ElemType;
typedef struct SSTable{
    ElemType *data;
    int len;
}SSTable;

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
        printf("%3d", ST.data[i]);
    }
    putchar('\n');
}


void swap(ElemType &a, ElemType &b){
    ElemType temp=a;
    a=b;
    b=temp;
}


//此处[low,mid]和[mid+1,high]是两个有序数组，该函数将这两个有序数组合并为一个数组
void Merge(ElemType *arr, int low,int mid,int high){
    //设置一个静态的辅助数组
    static ElemType B[10];
    int i,j,k;
    //将归并后的数组复制到B中
    for(k=low;k<=high;k++)
        B[k]=arr[k];

    //
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;){
        if(B[i]<B[j]){
            arr[k]=B[i];
            i++;
            k++;
        }else{
            arr[k]=B[j];
            j++;
            k++;
        }
    }
    //可能有剩余的元素，需要继续放入
    while(i<=mid)
        arr[k++]=B[i++];
    while(j<=high)
        arr[k++]=B[j++];
}

void MergeSort(ElemType *arr, int low, int high){
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}

int main() {
    SSTable ST;
    SSTable_Init(ST, 10);
    SSTable_print(ST);

    MergeSort(ST.data, 0, 9);
    SSTable_print(ST);



    return 0;
}
