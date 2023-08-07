#include <cstdio>
#include <cstdlib>

//专门用于定义数组中的元素, 以后修改起来更为方便
typedef int ElemType;

//如果在结构体内使用自身, 则定义时需要加上结构的名称
typedef struct LNode{
    ElemType data;
    struct LNode *next; //虽然此处结构体并没有定义完成, 但仍然可以使用该结构体
}LNode, *LinkList;

//此处LNode*和新定义的LinkList都是结构体指针, 两者是等价的,
//LinkList一般使用较多(因为不需要*号标记)

void print_list(LinkList L){
    //头节点一般不存放数据, 读取时应注意
    L = L->next;

    while(L != nullptr){
      printf("%3d", L->data);
      L=L->next;
    }
    putchar('\n');
}

void list_head_insert(LinkList &L){
    //声明头指针
    //申请的空间大小需要为LNode结构体的大小, 不能是指针的大小
    L = (LinkList)malloc(sizeof(LNode));
    L->next = nullptr;
    //声明需要输入的元素
    ElemType x;
    scanf("%d", &x);

    //声明(第一个)节点
    LNode *s;

    //利用循环逐个读取输入的数据
    while(x != 9999){
        //分配节点的空间
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;

        //将scanf语句写在最后, 从而不读取最后一个数据
        scanf("%d", &x);
    }

}

void list_tail_insert(LinkList &L){
    //为头节点申请空间
    L = (LinkList)malloc(sizeof(LNode));
    L->next = nullptr;
    //复制一个头节点作为尾节点
    //此处L, r指针指向的为同一个地址, 所以改变r时L也会同时改变
    LinkList r = L;

    //初始化赋值的数据
    ElemType x;
    scanf("%d",&x);

    LinkList s;
    while(x != 9999){
        //初始化新节点并赋值
        s = (LinkList)(malloc(sizeof(LNode)));
        s->data = x;

        //将尾节点(和头节点)都指向新的节点
        r->next = s;
        //将新节点用作新的尾节点
        r = s;
        scanf("%d", &x);
    }

    r->next = nullptr;
}

int main() {
    LinkList L;

//    list_head_insert(L);
    list_tail_insert(L);
    print_list(L);

    return 0;
}
