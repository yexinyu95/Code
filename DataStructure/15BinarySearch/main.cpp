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
