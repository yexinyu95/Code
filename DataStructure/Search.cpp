#include <cstdio>
#include <cstdlib>

typedef int ElemType;
typedef struct BSTNode{
    ElemType data;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BiTree;


/*
 * 只能用于有序的顺序表的查找，时间复杂度为O(log n)
 * 长度len为顺序表元素个数（从1开始）
 */
int BinarySearch(int *ar, int len, ElemType key){
    //1. 
    int low=0, high=len-1;
    int mid;

    //2.开始循环，循环条件为low和high没有相遇
    while (low<=high)
    {
        //2.1
        mid=(low+high)/2;

        //2.2 改变循环变量的值；一共有3种可能
        if(ar[mid]==key)     //查找到了
            return mid;
        else if(ar[mid]>key) //将high的值前移，找前半部分
            high=mid-1;
        else                 //将low的值后移，找后半部分
            low=mid+1;
    }

    //3.
    return -1; 
}

/*
 * 构造二叉排序树的辅助函数，用于将节点插入树中
 * 接受一个父节点T，和一个需要插入的元素k
 */
bool BST_Insert(BiTree &T, ElemType k){
    //1. 判断是否为根节点，只有第一次时会进行
    if(nullptr==T){
        T=(BiTree)calloc(1, sizeof(BSTNode));//分配空间，存储数据
        T->data=k;
        return true;
    }

    //2. 新建两个节点
    BiTree p=T;     //用来向下遍历，找到可以存放的节点；初始化为根节点
    BiTree parent=nullptr;  //用来存储（可以存放的节点的）父节点；可以初始化为nullptr
    
    //3. 通过循环寻找节点，结束条件为p为空节点（即p的父节点的子节点可以存）
    while(p){
        //3.1 先存储当前节点，然后再开始遍历
        parent=p;       

        //3.2 理论上，二叉排序树不能存储同样的数据，所以此处在遇到同样的值时返回false，
        if(k==p->data)  
            return false;
        
        //3.3 根据大小，判断p向左走还是向右走
        else if(k<p->data)
            p=p->lchild;
        else
            p=p->rchild;
    }

    //4. 将数据存进找到的位置
        //4.1 新建空间，将数据存进去
    BiTree treeNode=(BiTree)calloc(1, sizeof(BSTNode));
    treeNode->data=k;

        //4.2 返回的是父节点，所以还需要再判断一次大小，确定是存到左侧还是右侧
    if(k>parent->data){
        parent->rchild=treeNode;
        return true;
    }
    else{
        parent->lchild=treeNode;
        return true;
    }

    //(5. 如果走到这里，则说明出现了某些错误)
    return false;
}

/*
 * 主函数，构造二叉排序树
 */
BiTree Create_BST(BiTree &T){
    //1. 初始化为nullptr
    T=nullptr;

    //2. 类似层次建树，通过scanf读取数据
    ElemType data;
    while(scanf("%d", &data)){
        BST_Insert(T, data);
    }

    //3. 返回树根
    return T;
}

void DeleteNode(BiTree &T, ElemType x){
    //1. 
    if(nullptr==T)
        return;

    //2. 通过递归寻找需要删除的节点
    if(T->data > x)//递归时传入的参数为子树，以后也是对子树进行运算，所以不会影响根节点
        DeleteNode(T->lchild, x);
    else if(T->data < x)
        DeleteNode(T->rchild, x);
    

    //3. 
    else{
        //3.1 
        if(T->lchild==nullptr){
            BiTree tempNode = T;
            T=T->rchild;
            free(tempNode);
        }
        //3.2
        else if(T->rchild==nullptr){
            BiTree tempNode = T;
            T=T->lchild;
            free(tempNode);
        }

        //3.3
        else{
            //3.3.1
            BiTree tempNode=T->lchild;
            //3.3.2
            while (tempNode->rchild!=nullptr)
                tempNode=tempNode->rchild;
            //3.3.3
            T->data=tempNode->data;
            //3.3.4
            DeleteNode(T->lchild, tempNode->data);
        }
    }
}

void InOrder(BiTree T){
    if(T!=nullptr){
        InOrder(T->lchild);
        printf("%3d",T->data);
        InOrder(T->rchild);
    }
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


int main(void){
    BiTree T;
    T=Create_BST(T);
    InOrder(T);
    putchar('\n');

    DeleteNode(T, 8);
    InOrder(T);
    return 0;
}