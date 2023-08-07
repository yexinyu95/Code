#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct {
    //申请的空间的起始地址
    ElemType *elem;
    //存储的元素的个数
    int TableLen;
}SSTable;

void ST_Init(SSTable &ST, int len){
    //多申请了一个位置，为了存储哨兵；但哨兵的使用不是必须的
    ST.TableLen=len+1;
    ST.elem=(ElemType*)malloc(sizeof(ElemType)*ST.TableLen);

    int i;

    //生成随机数并填充进数组，考研不需要掌握
    srand(time(NULL));
    for (i = 0; i < ST.TableLen; i++) {
        ST.elem[i]=rand()%100;
    }
}

void ST_print(SSTable ST){
    int i;
    for(i=1;i<ST.TableLen;i++){
        printf("%3d", ST.elem[i]);
    }
    putchar('\n');
}

int Search_Seq(SSTable ST, ElemType key){
    //让零号元素作为哨兵
    ST.elem[0]=key;

    int i;
    for (i=ST.TableLen-1;ST.elem[i]!=key;i--) {
    }
    return i;
}

int BinarySearch(SSTable L, ElemType key){
    //此处设置的为数组的下标值，不是数组中的数据的值
    int low=0;
    int high=L.TableLen-1;
    int mid;

    //设置为小于等于，为了保证mid可以取到low和high的值
    while(low<=high){
        mid=(low+high)/2;
        if(key>L.elem[mid]){
            low=mid+1;
        }else if(key<L.elem[mid]){
            high=mid-1;
        }else{
            return mid;
        }
    }

    return -1;
}

//函数名存储的是函数的入口地址，也是一个指针
//left和right指向数组中的任意两个元素
//qsort规定，如果left指向的值大于right指向的值，则返回正值；小于时返回负值，相等时返回0
int compare(const void *left, const void *right){
    return *(int*)left-*(int*)right;
}



//考研真题实战（查找两个等长有序数组的中位数）
int find_median(int A[], int B[], int len){
    //1. 初始化下标，注意下标从0开始
    int low1=0, low2=0;
    int high1=len-1, high2=len-1;
    int mid1,mid2;

    //2.开始循环，结束条件为两个数组都只剩一个元素
    //此处的关键是“舍弃”的元素的个数要相等，
    while(low1==high1&&low2==high2){
        //2.1 找出现在的数组的中位数
        mid1=(low1+high1)/2;
        mid2=(low2+high2)/2;

        //2.2 情况一：两者相等，可以直接返回
        if(A[mid1]==B[mid2])
            return A[mid1];

            //2.3 情况二：A更小，说明A前面的元素不是中位数、B后面的元素不是中位数
        else if(A[mid1]<B[mid2]){
            if((low1+high1)%2==0){  //判断长度是否为偶数，
                low1=mid1;
                high2=mid2;
            }
            else{                   //如果为奇数，则需要将low移到mid的下一位
                low1=mid1+1;
                high2=mid2;
            }
        }

            //2.4 情况三：B更小，说明B前面的元素不是中位数、A后面的元素不是中位数
        else{
            if((low1+high1)%2==0){
                high1=mid1;
                low2=mid2;
            }
            else{
                high1=mid1;
                low2=mid2+1;
            }
        }
    }

    //3. 返回最后的两个中位数中更小的一个（可以根据题目示例判断）
    return A[low1]<A[low2]?A[low1]:B[low2];
}



int main() {
    SSTable ST;
    ST_Init(ST, 10);
    ST_print(ST);

    qsort(ST.elem, ST.TableLen, sizeof(ElemType), compare);
    ST_print(ST);

    ElemType key;
    printf("search key:\n");
    scanf("%d", &key);

    int pos = Search_Seq(ST,key);
    if(pos){
        putchar('T');
    } else{
        putchar('F');
    }



    return 0;
}
