#include<cstdio>
#include<cstdlib>
#include<cstring>

#define MAXSIZE 50
typedef int ElemType;


/*
链表实现的栈
基本类似单链表的实现，考察次数较少
必须使用头插法，否则无法实现出栈操作
*/
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode, *LkStack;

//初始化，
void InitLkStack(LkStack &S){
    S==nullptr;
}


bool Push(LkStack &S, ElemType x){
    //1.
    LinkNode* NODE=(LinkNode*)malloc(sizeof(LinkNode));
    if(NODE==nullptr)
        return false;
    NODE->data=x;
    NODE->next=nullptr;

    //2.
    if(S==nullptr)
        S=NODE;

    //3.
    else{
        NODE->next=S->next;
        S->next=NODE;
    }
    return true;
}


bool Pop(LkStack &S, ElemType &x){
    //1.
    if(S==nullptr)
        return false;

    //2.
    LinkNode* temp=S;
    x=temp->data;

    //3.
    S=S->next;
    free(temp);

    return true;
}


int main(){

    return 0;
}