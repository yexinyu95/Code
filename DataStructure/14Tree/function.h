//
// Created by abc on 2023/7/20.
//

#ifndef INC_14TREE_FUNCTION_H
#define INC_14TREE_FUNCTION_H

#include <cstdio>
#include <cstdlib>
typedef char BiElemType;

typedef struct BiTNode{
    BiElemType c;
    struct BiTNode *lchild;//不同于链表，树的节点中存储了两个指针：一个指向左子树，一个指向右子树
    struct BiTNode *rchild;
}BiTNode, *BiTree;
/*
三叉链表
对于经常需要查找父节点的情况，由于二叉树同样不能逆向遍历，
所以也可以在结构体中加入一个父节点`struct BiTNode *parent;`，
*/


typedef BiTree ElemType;

//设置一个辅助队列（链表），用来实现建树
typedef struct LinkNode{
    //存储的数据为树的某一个节点的地址（指针），并不是存储了整个节点
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef LinkNode* LinkList;

typedef struct LinkQueue{
    LinkNode *front, *rear;
}LinkQueue;


void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=NULL;
}

bool IsEmpty(LinkQueue Q){
    if (Q.front==Q.rear){
        return true;
    }
    return false;
}

int QueueLength(LinkQueue Q){
    int i=0;
    while(Q.front!=Q.rear){
        Q.front=Q.front->next;
        i++;
    }
    return i;
}

void EnQueue(LinkQueue &Q, ElemType x){
    //1. 初始化节点并存入数据
    LinkNode *pnew = (LinkNode*)malloc(sizeof(LinkNode));
    pnew->data=x;
    pnew->next=NULL;

    //2. 改变指针
    Q.rear->next=pnew;    //先通过尾指针将next指向新的数据
    Q.rear=pnew;          //再将尾指针指向新的尾部
}

bool DeQueue(LinkQueue &Q, ElemType &x){
    //1. 出队前先判断是否为空
    if (Q.front==Q.rear)
        return false;

    //2. 备份出队的节点
    LinkNode *q=Q.front->next;
    //存储数据
    x=q->data;

    //3. 将头指针指向新的头部
    Q.front->next=q->next;
    if(Q.rear==q)
        Q.rear=Q.front;

    //4. 释放空间
    free(q);
    return true;
}


#endif //INC_14TREE_FUNCTION_H
