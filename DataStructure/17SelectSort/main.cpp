#include <cstdio>
#include <cstdlib>
#include <ctime>

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

void SelectSort(ElemType *ar, int len){
    int i,j,min;
    for (i = 0; i < len; ++i) {//此处的len改为len-1也可
        min = i;
        for (j = i + 1; j < len; ++j) {
            if (ar[j] <= ar[min]) {
                min = j;
            }
        }
        if(min!=i)//可以加上一个判断，只有i和min不相等时才交换
            swap(ar[i], ar[min]);
    }
}

//https://www.cs.usfca.edu/~galles/visualization/HeapSort.html
/*
 * 堆排序的辅助函数，目的是将一个子树调整为大根堆
 * 接受三个参数，第一个是数组，第二个是数组长度；
 * 第三个是待排序元素所在的层数，
 */
void AdjustDown(ElemType *ar, int len, int dad){
    //1计算左子节点的下标（树的性质）
    int lchild=2*dad+1;

    //2需要使用循环，
    //因为子树可能还有子树，要一直调整下去，直到最后的子节点；
    //判断方式为子节点的下标是否超过了数组长度
    while(lchild<len){
        //2.1判断右子树，如果右子树存在且更大，则取右子树
        if(lchild+1<len&&ar[lchild]<ar[lchild+1])//A1:>为降序，<为升序；需要与A2同时调整
            lchild++;

        //2.2判断哪个节点更大
        if(ar[lchild]>ar[dad]) {//A2:<为降序，>为升序
            //2.2.1调整子节点与父节点
            swap(ar[lchild], ar[dad]);

            //2.2.2将lchild重新作为dad，判断下面的子树是否需要重新调整
            dad=lchild;
            lchild=2*dad+1;
        }

        //2.3可以减少循环次数，理论上可以不写
        else
            break;
    }
}

/*
 * 堆排序的主函数，接受一个数组和数组长度
 */
void HeapSort(ElemType *ar, int len){
    int i;
    //1按层（父节点）进行调整（i的取值为层数），将堆调整为大根堆
    for(i=len/2-1;i>=0;i--){
        AdjustDown(ar,len,i);
    }

    //2交换根部（最大的数）与最后一个元素，此时最后一个元素为最大的数（已经有序）
    swap(ar[0],ar[len-1]);

    //3重复上述步骤，交换其它元素
    for(i=len-1;i>1;i--){//i代表的是剩余的无序数的数组的长度
        //3.1交换完后，0号元素不满足大根堆，所以需要将0传入
        AdjustDown(ar,i,0);
        //3.2再交换新的“根部”和新的“最后一个元素”
        swap(ar[0],ar[i-1]);
    }
}

int main() {
    //int ar[] = {3,87,2,93,78,56,61,38,12,40};

    SSTable ST;
    SSTable_Init(ST,10);
    SSTable_print(ST);

    HeapSort(ST.data,ST.len);
    SSTable_print(ST);

    return 0;
}
