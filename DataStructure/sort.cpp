#include <cstdio>
#include <cstdlib>

typedef int ElemType;

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

/*
 * 堆排序的辅助函数，目的是将一个子树调整为大根堆
 * 接受三个参数，第一个是数组，第二个是数组长度；
 * 第三个是待排序元素所在的层数，
 */
void AdjustDown(ElemType A[], int len, int floor){
    //1. 根据元素所在的层数，设置左子树的下标
    int dad=floor;
    int lchild=2*dad+1;

    //2. 开启循环；循环的目的是遍历子树的所有子节点，结束条件为子节点的下标超过数组长度
    while (lchild<=len)
    {
        //2.1 判断是否有右子树，以及右子树是否更大
        if(lchild+1<=len&&A[lchild]<A[lchild+1])
            lchild++;
        
        //2.2 如果左子树（或右子树）比父节点大，则交换两者
        if(A[lchild]>A[dad]){
            swap(A[lchild], A[dad]);

            dad=lchild;       //将左子树设置为新的父节点
            lchild=2*lchild+1;//设置新的左子树
        }else
            break;
    }
}

/* 
 * 堆排序的主函数，接受一个数组和数组长度
 * 
 */

void HeapSort(ElemType A[], int len){
    int i;

    //1. 从最后一个父节点开始，将数组调整为大根堆
    for(i=len/2; i>=0; i--)
        AdjustDown(A,len,i);
    
    //2. 此时最顶端的元素A[0]一定为最大的元素，将其与最后一个元素交换
    swap(A[0],A[len]);

    //3. 刨去最后一个元素，将剩余的树重新调整为大根堆，
    for(i=len-1;i>0;i--){
        AdjustDown(A,i,0);
        swap(A[0],A[i]);  //再将最顶端的元素逐个放到数列最后
    }
}


int main(void){
    ElemType A[]={3,87,2,93,78,56,61,38,12,40};
    HeapSort(A, 10);

    for (auto &&i : A)
    {
        printf("%3d",i);
    }
    
    return 0;
}