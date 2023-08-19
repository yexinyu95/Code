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

//类似链表的尾插法，
void EnQueue(LinkQueue &Q, ElemType x){
    //0. 由于通过新增一个节点入队，所以此处没有“队满”的概念

    //1. 申请新的节点，然后将数据存进去
    LinkNode *pnew = (LinkNode*)malloc(sizeof(LinkNode));
    pnew->data=x;

    //2. 入队时，将新节点加入到尾指针后；再将尾指针指向新的尾部
    Q.rear->next=pnew;
    Q.rear=pnew;

    //3. 不同于链表，此处每一个新插入的节点都是尾节点，所以需要将next初始化为nullptr
    pnew->next=nullptr;
}

bool DeQueue(LinkQueue &Q, ElemType &x){
    //1. 先判断队是否为空
    if (EmptyQueue(Q))
        return false;

    //2. 找到第一个节点，将指针存进q以便free，将数据存进变量x
    LinkNode *q;
    q=Q.front->next;//类似链表，队列的头节点也不存数据，
    x=q->data;

    //3. 将头节点（而不是头指针front）指向新的头部
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
void InitCircleQueue(LinkQueue &Q){
    Q.rear=Q.front=(LinkList)malloc(sizeof (LinkNode));
    //实现方式基本类似，只是这里的初始节点指向自己，
    Q.rear->next=Q.front;
}

void EnQueue(LinkList front, LinkList &rear, ElemType x){
    //1. 判断队列是否已满，如果不满，则可以直接放入值，然后将尾节点后移
    if(rear->next!=front){
        rear->data=x;
        rear=rear->next;
    }

        //2. 若满了则需要新申请空间，然后将新的节点作为尾节点，
    else{
        LinkList pnew;
        pnew=(LinkList)malloc(sizeof(LinkNode));

        rear->data=x;//队列的尾节点是不存数据的，所以数据实际还是放在原来的尾节点中
        rear->next=pnew;
        rear=pnew;

        rear->next=front;
    }
}

void DeQueue(LinkList &front, LinkList rear, ElemType &x){
    if(front==rear)
        return;
    else {
        x = front->data;
        front = front->next;
    }
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
