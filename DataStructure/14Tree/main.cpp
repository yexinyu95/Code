#include "function.h"
#include <cstdio>
#include <cstdlib>


/*
 * 二叉树的层次建树，即类似广度优先的方式，按每一层从左到右逐个填充节点，
 * 填充满后再从左到右，依次填充下一层，
 * 使用scanf读取控制台输入的char数据，如abcdefghij，
 */
BiTree InitTree(BiTree T){
    //1. 将输入的指针作为树根节点，并将其初始化为nullptr
    T=nullptr;

    //2. 新建一个指针，指向需要新加入树的节点
    BiTree treeNode;

    //3. 初始化辅助队列（实际上更类似链表，因为没有删除过节点，所以头指针并没有用到）
    //3.1 队列的头指针和尾指针
    LinkList L=nullptr, tail=nullptr;

    //3.2 指向加入队列的节点的指针
    LinkList queueNode=nullptr;

    //3.3 指向还没有满的树的节点的指针
    // 此处的pcur与tail是不同步的，
    // 因为树有两个子节点，只有两个都满了以后，pcur才会向前移动
    // 但是为了维持队列，尾指针tail需要一直向前移动；
    LinkList pcur=nullptr;

    //4. 新建一个字符变量用于接受读取的数据
    char c;

    //5. 开始循环，结束条件为输入其它数据类型或输入换行符
    while (scanf("%c", &c)){  //scanf根据占位符，一次从缓冲区读取一个数据，赋值一个数据，再向后读取；而不是一次都读取完
                                    // 因此此处可以直接输入abcdefghij（会被存入缓冲区），然后回车
        if('\n'==c)
            break;//读到换行时停止

        //5.1 calloc申请的空间大小为两个参数直接相乘；并且会对空间进行初始化，将其赋值为0；利于树的空节点的判断
        treeNode=(BiTree)calloc(1,sizeof(BiTNode));

        //5.2 将数据存储进节点
        treeNode->c=c;

        //5.3 初始化辅助队列，将需要加入的节点存进去
        queueNode=(LinkList)calloc(1, sizeof(LinkNode));
        queueNode->data=treeNode;

        //5.4 判断树（根）是否为空，只有第一次时会执行
        if(nullptr==T){
            //将tree指向树的根节点
            T=treeNode;
            //辅助队列的头和尾都指向第一个节点
            L=tail=queueNode;
            //pcur指向要进入树的父节点
            pcur=queueNode;
        }

        //5.5
        else{
            //5.5.1 让元素先入队列，以便后续pcur指针找到新的节点
            tail->next=queueNode;
            tail=queueNode;

            //5.5.2 将下一个节点放入树中
            if(nullptr==pcur->data->lchild){
                //若pcur->data的左节点为空，则放入左节点；由于树的右节点还没有数据，所以pcur是不移动的
                pcur->data->lchild=treeNode;
            }else if(nullptr==pcur->data->rchild){
                //若pcur->data的右节点为空，则放入右节点
                pcur->data->rchild=treeNode;
                //此时该节点已满，将队列中的辅助指针指向下一个节点
                pcur=pcur->next;
            }
        }
    }

    return T;
}

//广度优先遍历，也叫层次遍历、层序遍历
void LevelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q);
    //存储出队的节点
    BiTree p;

    //将根节点入队
    EnQueue(Q, T);

    while(!IsEmpty(Q)){
        DeQueue(Q, p);
        putchar(p->c);
        if(p->lchild!=NULL){
            EnQueue(Q, p->lchild);
        }
        if(p->rchild!=NULL){
            EnQueue(Q, p->rchild);
        }
    }
}

//前序遍历，结果等同于深度优先遍历
void PreOrder(BiTree p){
    if(NULL!=p) {
        printf("%c", p->c);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

//中序遍历
void InOrder(BiTree p){
    if(NULL!=p) {
        InOrder(p->lchild);
        printf("%c", p->c);
        InOrder(p->rchild);
    }
}

//后序遍历
void PostOrder(BiTree p){
    if(NULL!=p) {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        printf("%c", p->c);
    }
}

/*
 * 二叉树的深度
 */
int maxDepth(BiTree node){
    //1. 边界条件，即结束递归的条件
    if(node==nullptr)
        return 0;

    //2. 开始递归
    else{
        int left=maxDepth(node->lchild);
        int right=maxDepth(node->rchild);

        int depth=(left>right)?left:right;
        return depth+1;
    }
}

int max=0;
int diameterHelper(BiTree root){
    //1.
    if(root->lchild==nullptr&&root->rchild==nullptr)
        return 0;

    //2.
    else{
        int leftSize=root->lchild==nullptr?0:diameterHelper(root->lchild)+1;
        int rightSize=root->rchild==nullptr?0:diameterHelper(root->rchild)+1;

        max=max>(leftSize+rightSize)?max:(leftSize+rightSize);

        return leftSize>rightSize?leftSize:rightSize;
    }
}
/*
 * 二叉树的直径（两个节点的最长距离）
 *
 */
int diameterOfBinaryTree(BiTree root) {
    //1.
    if (root == nullptr)
        return 0;

    //2.
    else{
        diameterHelper(root);
        return max;
    }
}

//考研真题实战

int wpl=0;
void wpl_PreOrder(BiTree p, int deep){
    //(1.)
    if(nullptr==p)
        deep=0;
    //2.
    else{
        //可以打印出节点对应的层数
        //printf("ele%c--%d.\n", p->c, deep);
        if(p->lchild==nullptr&&p->rchild==nullptr){
            wpl=wpl+deep*p->c;
        }
        wpl_PreOrder(p->lchild, deep+1);
        wpl_PreOrder(p->rchild, deep+1);
    }
}


int main() {

    int matrix[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8}};

    return 0;
}
