#include <cstdio>
#include <cstdlib>
#define MAXSIZE 50

// 定义了存储的数据，使用ElemType便于后续进行更改
typedef int ElemType;

/*
双链表的元素为一个结构体：
包括存储的数据，一个指向上一个节点的指针，一个指向下一个节点的指针
*/
typedef struct DNode{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DNode, *DLinkList;


bool InitDLinkList(DLinkList &L){
    L=(DNode*)malloc(sizeof(DNode));
    if(L==NULL)
        return false;
    
    L->prior=L->next=nullptr;
    return true;
}


bool InitCircleDLinkList(DLinkList &L){
    L=(DNode*)malloc(sizeof(DNode));
    if(L==NULL)
        return false;
    
    L->prior=L->next=L;
    return true;
}

/*
头插法新建双向链表；
*/
void Dlist_head_insert(DLinkList &D){
    //1. 分配空间
    D=(DLinkList)malloc(sizeof(DNode));
    D->prior=nullptr;//头节点的前指针和后指针都要初始化为nullptr
    D->next=nullptr;

    //2. 初始化变量并读取值
    ElemType x;
    scanf("%d", &x);

    //3. 初始化一个节点
    DLinkList s;

    //4. 通过循环插入节点
    while (x!=9999){
        s=(DLinkList)malloc(sizeof(DNode));
        s->data=x;

        s->next=D->next;
        //双链表特有的设置前指针的步骤
        if(D->next!= nullptr)//第一次没有这一步，因为此时新插入的节点和临时节点都是s自己；此时D->next还没有更改，所以可以用nullptr判断，
            D->next->prior=s;//从第二次开始，将已有的D的下一个节点的前指针，指向新插入的临时节点s
        s->prior=D;          //将新插入的节点s的头指针指向D
        D->next=s;
    }
}
/*
尾插法新建双向链表；
*/
void Dlist_tail_insert(DLinkList &D){
    //1. 分配空间
    D=(DLinkList)malloc(sizeof(DNode));
    D->prior=nullptr;//头节点的前指针和后指针都要初始化为nullptr
    D->next=nullptr;

    //2. 初始化变量并读取值
    ElemType x;
    scanf("%d", &x);

    //3. 初始化一个节点指针，还需要另一个节点指针作为尾指针
    DLinkList s;
    DLinkList r=D;

    //4. 通过循环插入节点
    while (x!=9999){
        s=(DLinkList)malloc(sizeof(DNode));
        s->data=x;

        r->next=s;
        //设置双链表特有的一步；不同与单链表，双链表的尾插法比头插法更好理解，
        s->prior=r;
        r=s;
    }
    //5. 最后要将尾节点r的next设置为nullptr
    r->next= nullptr;
}



/*
按照位置在双向链表中插入元素，接受一个需要插入的值，和该元素插入的位置（从1开始）
*/
bool DListFrontInsert(DLinkList D, int i, ElemType value){
    //1. 新建一个指针，并指向需要插入的位置的上一个节点
    DLinkList pre = DIndexElem(D, i-1);

    //2. 通过查找元素函数，判断插入的位置是否合法（上一个节点中的指针不能为空）
    if(nullptr==pre)
        return false;

    //3. 新建一个指针，然后分配空间并赋值
    DLinkList ins = (DLinkList)malloc(sizeof(DNode));
    ins->data=value;

    //4.
    ins->next=pre->next;  //将上一个节点指向的节点，赋值给这个新的节点指向的节点
    if(pre->next)
        pre->next->prior=ins; 
        //将上一个节点的原来的下一个节点的头指针指向新插入的节点
    ins->prior=pre;       //新插入的节点的头指针指向上一个节点
    pre->next=ins;        //将上一个节点指向新节点

    return true;
}


/*
删除给定位置的节点，位置从1开始
*/
bool DListDelete(DLinkList D, int i){
    //1. 初始化一个指针，并通过查找函数将其赋值为需要删除的节点的前一个节点
    DLinkList pre= DIndexElem(D, i-1);

    //2. 判断位置是否合法
    if(NULL==pre)
        return false;

    //3. 将需要删除的节点记录下来
    DLinkList temp=pre->next;
    //4. 将需要删除的节点指向的节点，赋值给上一个节点指向的节点
    pre->next=temp->next;

    //5. 不同于单链表，需要判断是否还有改变头节点的必要
    if(temp->next){//如果下一个指针是空指针（到达尾部），则空指针不再对应节点
        temp->next->prior=pre;
    }

    //6. 最后需要释放删除的节点的空间
    free(temp);

    return true;
}

/*
删除给定节点的后继节点
*/
bool DListDelete(DLinkList pre, ElemType &val){
    //1.
    if(pre==nullptr)
        return false;
    
    //2.
    if (pre->next==nullptr)
        return false;
    
    //3.



}


//双链表的查找与单链表类似
DLinkList DIndexElem(DLinkList D, int SearchPos){
    //1. 先判断搜索的位置的合法性
    if(SearchPos<=0)
        return nullptr;

    //2. 通过遍历链表判断位置，同时检查L是否为空指针
    int i;
    for(i=0; D&&i<SearchPos; i++)
        D=D->next;

    return D;
}


struct Node{
	ElemType data;
	int next;
};

typedef Node SLinkList[MAXSIZE];

bool InitSLinkList(SLinkList SL){
    
}



int main(void){


    return 0;
}