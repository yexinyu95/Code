#include <cstdio>
#include <cstdlib>

typedef int ElemType;

//队列中用于存储数据的节点
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode, *LinkList;

//链表本身实际上就是一个头指针
//队列本身，也只存放头指针和尾指针，而不是具体的数据；
typedef struct LinkQueue{
    LinkNode *front, *rear;
}LinkQueue;


void InitQueue(LinkQueue &Q){
    //1. 初始化队列，申请一个头节点，然后将头指针和尾指针都指向这个节点
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));

    //2. 将这个节点指向NULL；类似链表，这里的头节点也不存数据
    Q.front->next=nullptr;
}

//判断队空的方式类似顺序队列，
bool EmptyQueue(LinkQueue Q){
    return Q.front==Q.rear;
}

//入队
void EnQueue(LinkQueue &Q, ElemType x){
    //0. 由于通过新增一个节点入队，所以此处没有“队满”的概念

    //1. 申请新的节点，然后将数据存进去
    LinkNode *pnew = (LinkNode*)malloc(sizeof(LinkNode));
    pnew->data=x;
    pnew->next=nullptr; //每一个新插入的节点都是尾节点，所以需要将next初始化为nullptr

    //2. 入队；类似链表的尾插法
    Q.rear->next=pnew;
    Q.rear=pnew;
}

//出队
bool DeQueue(LinkQueue &Q, ElemType &x){
    //1. 先判断队是否为空
    if (EmptyQueue(Q))
        return false;

    //2. 使用了头指针，所以先找到第一个节点，并将指针存进q以便free，将数据存进变量x
    LinkNode *q;
    q=Q.front->next;
    x=q->data;

    //3. 将头节点指向新的头部（使用了头指针，所以头指针一直指向头节点）
    Q.front->next=q->next;

    //4. 释放空间之前，先要判断出队的是不是最后一个元素；如果是，释放完了空间就没法判断了
    if(Q.rear==q)
        Q.rear=Q.front;//如果是就将队列置为空（都指向头节点）
    free(q);

    return true;
}



//考研真题实战
//1. 入队时可以增加空间
//2. 出队后，空间可以重复使用
//   2.1 不能释放空间
//   2.2 可以再次找到原来的节点
//3. 队列占用的空间只增不减


//采用循环链表的方式实现，
//实现方式基本类似，只是这里的初始节点指向自己，

void InitQueueCircle(LinkQueue &Q){
    Q.rear=Q.front=(LinkList)malloc(sizeof (LinkNode));
    Q.rear->next=Q.front;
}


//循环队列入队
void EnQueueCircle(LinkQueue &Q, ElemType val) {

    //1. 队列满，申请一个结点的空间，放入队列
    //循环队列的尾节点不存放数据，所以需要把入队元素放入原来的尾节点
    //再将申请的节点作为新的尾节点
    //（单链表不能反向查找，所以在尾节点前插入新节点是不能实现的）
    if (Q.rear->next == Q.front) {
        LinkList pnew=(LinkList) malloc(sizeof(LinkNode));
        Q.rear->data = val;    

        Q.rear->next = pnew;   
        pnew->next = Q.front;
        Q.rear = pnew;
    } 
    
    //2. 队列不满，直接放值，让 rear 后移一个结点
    else {
        Q.rear->data = val;
        Q.rear = Q.rear->next;
    }
}


//循环队列出队
bool DeQueueCircle(LinkQueue &Q, ElemType &x) {
    if (Q.front == Q.rear)
        return false;

    else {
        x=Q.front->data;
        Q.front = Q.front->next;
    }
    return true;
}



int main() {
    LinkQueue Q;
    bool ret;
    InitQueue(Q);

    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    EnQueue(Q, 6);
    EnQueue(Q, 7);

    ElemType x;
    DeQueue(Q, x);
    DeQueue(Q, x);
    DeQueue(Q, x);
    DeQueue(Q, x);
    DeQueue(Q, x);
    DeQueue(Q, x);
    DeQueue(Q, x);
    DeQueue(Q, x);

    return 0;
}
