#include <cstdio>
#define MAXSIZE 5

typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int front, rear;
}SqQueue;


void InitQueue(SqQueue &Q){
    //初始化循环队列；由于使用数组实现，所以头和尾都指向0
    Q.front=Q.rear=0;
}

bool isEmpty(SqQueue Q){
    //定义队列头、尾指向同一个位置时，队列为空
    return Q.rear==Q.front;
}

bool isFull(SqQueue Q){
    //为了与队列为空区分开，此处牺牲一个存储空间；所以判断条件可以写为队列尾向前一步是队列头
    return (Q.rear+1)%MAXSIZE==Q.front;
}

bool EnQueue(SqQueue &Q, ElemType x){
    //判断循环队列是否已满，
    if(isFull(Q))
        return false;
    //只能在队尾放入元素
    Q.data[Q.rear]=x;
    //加1后还需要再除以模长，这样就可以实现循环队列
    Q.rear=(Q.rear+1)%MAXSIZE;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x){
    //判断循环队列是否为空
    if(isEmpty(Q))
        return false;
    //只能从队首取出元素
    x=Q.data[Q.front];
    //减1后同样需要除以模长
    Q.front=(Q.front+1)%MAXSIZE;
    return true;
}

int main() {
    SqQueue Q;
    InitQueue(Q);

    bool empty;
    empty=isEmpty(Q);


    ElemType x;


    EnQueue(Q, 1);
    EnQueue(Q, 3);
    EnQueue(Q, 5);
    EnQueue(Q, 7);
    EnQueue(Q, 9);

    DeQueue(Q, x);
    DeQueue(Q, x);
    DeQueue(Q, x);
    DeQueue(Q, x);
    DeQueue(Q, x);

    EnQueue(Q, 2);
    EnQueue(Q, 4);
    EnQueue(Q, 6);
    EnQueue(Q, 8);
    EnQueue(Q, 10);

    DeQueue(Q, x);
    DeQueue(Q, x);
    DeQueue(Q, x);
    DeQueue(Q, x);
    DeQueue(Q, x);

    return 0;
}
