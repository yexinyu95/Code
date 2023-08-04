#include <cstdio>
#include <cstdlib>

typedef char BiElemType;
typedef struct BiTNode{
    BiElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode, *BiTree;

typedef BiTree ElemType;
typedef struct LinkNode{
    ElemType p;
    struct LinkNode *next;
}LinkNode, *LinkList;

BiTree InitTree (BiTree T){
    //1. 
    T=nullptr;
    BiTree treeNode;

    //2.
    LinkList head=nullptr, tail=nullptr;
    LinkList queueNode;
    LinkList pcur=nullptr;

    //3.
    char c;

    //4.
    while(scanf("%c", &c)){
        //4.1
        if(c=='\n')
            break;

        //4.2
        treeNode=(BiTree)calloc(1,sizeof(BiTNode));
        treeNode->data=c;
        //4.3
        queueNode=(LinkList)calloc(1,sizeof(LinkNode));
        queueNode->p=treeNode;

        //4.4
        if(nullptr==T){
            T=treeNode;
            head=tail=queueNode;
            pcur=queueNode;
            continue;
        }

        //4.5
        else{
            tail->next=queueNode;
            tail=queueNode;
        }

        //4.6
        if(nullptr==pcur->p->lchild){
            pcur->p->lchild=treeNode;
        }
        else if(nullptr==pcur->p->rchild){
            pcur->p->rchild=treeNode;
            pcur=pcur->next;
        }
    }
    //5.
    return T;
}

void PreOrder(BiTree p){
    if(nullptr!=p){
        printf("%c", p->data);
        PreOrder(p->lchild);
        PreOrder(p->rchild);        
    }
}

void InOrder(BiTree p){
    if(nullptr!=p){
        InOrder(p->lchild);
        printf("%c", p->data);
        InOrder(p->rchild);
    }
}

void PostOrder(BiTree p){
    if(nullptr!=p){
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        printf("%c", p->data);
    }
}




int main(void)
{
    BiTree T=nullptr;
    T = InitTree(T);
    InOrder(T);
    return 0;
}
