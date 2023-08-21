#include <cstdio>
#define MAXSIZE 5

typedef int ElemType;


typedef struct{
    ElemType data[MAXSIZE];
    int front, rear;
    //类似栈，此处默认队尾指针指向队尾元素的下一个位置；
    //也可以将队尾设置为指向队尾元素，此时代码逻辑需要一些改变；做题时应注意
}SqQueue;

//初始化循环队列；
//非循环的队列的空间使用效率较低，此处没有使用；
void InitQueue(SqQueue &Q){
    //由于使用数组实现，所以头和尾都指向0
    Q.front=Q.rear=0;
}

bool isEmpty(SqQueue Q){
    //定义队列头、尾指向同一个位置时，队列为空
    return Q.rear==Q.front;
}

//为了与队列为空区分开，此处牺牲一个存储空间；所以判断条件可以写为队列尾向前一步是队列头
bool isFull(SqQueue Q){
    return (Q.rear+1)%MAXSIZE==Q.front;
}
/*
避免存储空间浪费

1.在队列结构中新增一个size变量，用来记录队列中的元素数量。
2.在队列结构中新增一个tag变量，用来记录最后一次进行的操作；由于只有入队操作才可能导致
队满，所以如果队列头、尾指向同一个位置，且最后一次操作为入队，则说明已满。
*/




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
