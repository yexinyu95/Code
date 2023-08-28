#include "function.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

/*
 * 完全二叉树的层次建树，
 * 使用类似广度优先的方式，按每一层从左到右逐个填充节点；填充满后再从左到右，依次填充下一层，
 * 接受一个字符串参数，如"abcdefghij"；返回一个树的根节点
 */
BiTree InitTree(const char* str){
    //1. 设置树根节点，并将其初始化为nullptr
    BiTree T=nullptr;

    //2. 初始化辅助队列（实际上更类似链表，因为没有删除过节点，所以头指针并没有用到）
    LinkList L=nullptr, tail=nullptr;   //队列的头指针和尾指针
    LinkNode* pcur=nullptr;             //指向还没有满的树的节点的指针
    
    //此处的pcur与tail是不同步的，
    //因为树有两个子节点，只有两个都满了以后，pcur才会向前移动
    //但是为了维持队列，尾指针tail需要一直向前移动；

    //3. 开始循环，循环次数为字符串长度
    for(int i=0;i<strlen(str);i++){

        //3.1 使用calloc设置一个树的节点，并将数据存入
        BiTNode* treeNode=(BiTNode*)calloc(1,sizeof(BiTNode));    //calloc申请的空间大小为两个参数直接相乘；并且会对空间进行初始化，将其赋值为0；利于树的空节点的判断
        treeNode->c=str[i];

        //3.2 设置辅助队列的节点，并将树（的指针）存入
        LinkNode* queueNode=(LinkNode*)calloc(1, sizeof(LinkNode));
        queueNode->data=treeNode;

        //3.3 判断树（根）是否为空，只有第一次时会执行
        if(nullptr==T){
            T=treeNode;         //将tree指向树的根节点
            L=tail=queueNode;   //辅助队列的头和尾都指向第一个节点
            pcur=queueNode;     //pcur指向要进入树的父节点
        }

        //3.4
        else{
            //3.4.1 让元素先入队列，以便后续pcur指针找到新的节点
            tail->next=queueNode;
            tail=queueNode;

            //3.4.2 将下一个节点放入树中
            if(nullptr==pcur->data->lchild){
                //若pcur->data的左节点为空，则放入左节点；由于树的右节点还没有数据，所以pcur不移动
                pcur->data->lchild=treeNode;
            }
            else if(nullptr==pcur->data->rchild){
                pcur->data->rchild=treeNode;    //若pcur->data的右节点为空，则放入右节点
                pcur=pcur->next;                //此时该节点已满，将队列中的辅助指针指向下一个节点
            }
        }
    }
    return T;
}



/*
 * 二叉树的遍历方式
 * 前序、中序、后序遍历，采用递归方式实现
 * 层序遍历，采用辅助队列实现
 */

//访问节点需要进行的操作
void visit(BiTree T){
    printf("%c", T->c);
}

//前序遍历（根节点，左节点，右节点）；结果等同于深度优先遍历
void PreOrder(BiTree p){
    //1.
    if (p==NULL) return;

    //2. 
    if(NULL!=p) {
        visit(p);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

//中序遍历（左节点，根节点，右节点）
void InOrder(BiTree p){
    if(NULL!=p) {
        InOrder(p->lchild);
        visit(p);
        InOrder(p->rchild);
    }
}

//后序遍历（左节点，右节点，根节点）
void PostOrder(BiTree p){
    if(NULL!=p) {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        visit(p);
    }
}

//广度优先遍历，也叫层次遍历、层序遍历；使用辅助队列实现
void LevelOrder(BiTree T){
    //1. 初始化辅助队列
    LinkQueue Q;
    InitQueue(Q);

    //2. 存储出队的节点
    BiTree p;

    //3. 将根节点入队
    EnQueue(Q, T);
    int len=QueueLength(Q);

    //4. 外层循环，结束条件为队列中没有元素
    while(len){
        //4.1 内层循环，次数为上次队列的元素数量（即上一层的节点数）
        for (size_t i = 0; i < len; i++){
            DeQueue(Q, p);  //将上次队列的所有元素出队（一次出队一个）
            visit(p);       //对节点数据进行操作
                            
            if(p->lchild!=NULL)         //将这一层的节点的子节点（一定在下一层）入队
                EnQueue(Q, p->lchild);
            if(p->rchild!=NULL)
                EnQueue(Q, p->rchild);
        }

        //4.2 对一层的数据进行操作
        putchar('\n');

        //4.3 更新队列的长度
        len=QueueLength(Q);
    }
}

/*
将二叉树转化为线索二叉树
需要先定义线索二叉树的节点结构，即加入了标记线索节点的bool变量

基本思路类似遍历的实现方式
核心思想是声明一个额外的指针，用来记录前驱节点，
*/

//辅助函数，基本操作类似中序遍历
//pre需要进行修改，因此设置为引用
void InThreadHelper(ThreadTree T, ThreadNode* &pre){
    if(T!=nullptr){
        InThreadHelper(T->lchild, pre);
        visit(T, pre);
        InThreadHelper(T->rchild, pre);
    }
}

//将二叉树转化为中序线索二叉树
//主函数，用来引入指针pre；指向当前访问节点的前驱节点
void InThread(ThreadTree T){
    //1.
    if(T==nullptr)
        return;
    //2. 第一个节点没有前驱，所以将pre初始化为nullptr
    ThreadNode *pre=nullptr;   

    //3.
    InThreadHelper(T, pre);

    //4.处理最后一个访问的节点
    pre->rchild==nullptr;
    pre->rtag=true;        
}

void PreThreadHelper(ThreadNode* root, ThreadNode* &pre){
    if(root!=nullptr){
        visit(root, pre);
        /*
        线索化之后，左节点会被设置为前驱节点；根据先序遍历的规则，此处会导致循环访问的问题
        所以需要根据标志位ltag判断是否还需要遍历
        */
        if(!root->ltag)
            PreThreadHelper(root->lchild, pre);
        else
            return;
        PreThreadHelper(root->rchild, pre);
    }
}

void PreThread(ThreadNode* root){
    //1.
    if(root==nullptr);
        return;
    //2.
    ThreadNode* pre=nullptr;

    //3.
    PreThreadHelper(root, pre);

    //4.
    pre->rchild==nullptr;
    pre->rtag=true;   
}

void PostThreadHelper(ThreadNode* p, ThreadNode* &pre){
    if(p!=nullptr){
        PostThreadHelper(p->lchild, pre);
        PostThreadHelper(p->rchild, pre);
        visit(p, pre);
    }
}

void PostThread(ThreadNode* root){
    //1.
    if(root==nullptr)
        return;
    //2.
    ThreadNode* pre=nullptr;
    //3.
    PostThreadHelper(root, pre);
    //4.
    pre->rchild=nullptr;
    pre->rtag=true;
}

//访问时进行的操作，判断是否有空的子树，然后根据前指针将前指针赋值给空子树
//也可以直接写在遍历函数内
void visit(ThreadNode *q, ThreadNode* &pre){
    //1. 设置前驱节点，此时pre为q的前驱节点
    if(q->lchild==nullptr){
        q->lchild=pre;
        q->ltag=true;
    }
    //2. 设置后继节点，此时q为pre的后继节点
    if(pre!=nullptr&&pre->rchild==nullptr){
        pre->rchild=q;
        pre->rtag=true;
    }
    //3. 将pre指针前移到q的位置
    pre=q;
}


/*
二叉树的应用
*/

//二叉树的深度
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

//二叉树的直径（两个节点的最长距离）
//需要一个辅助函数和一个全局变量
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


//考研真题，计算二叉树的权值
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
    BiTree p=InitTree("abc");
    PreOrder(p);
    return 0;
}
