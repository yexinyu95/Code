#include <cstdio>
#include <cstdlib>


// 定义了存储的数据，使用ElemType便于后续进行更改
typedef int ElemType;

/*
定义单链表的元素，为一个结构体：包括存储的数据和一个指向下一个节点的指针
*/
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

/*
定义双链表的元素，为一个结构体：包括存储的数据，一个指向上一个节点的指针，一个指向下一个节点的指针
*/
typedef struct DNode{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DNode, *DLinkList;


/*
头插法新建链表；因为要修改链表，所以需要加引用
*/
void list_head_insert(LNode* &L)
{
    //1. 申请头节点的空间，并将其赋值为空
    L=(LinkList)malloc(sizeof(LNode));
    L->next = nullptr;

    //2. 初始化数据变量，并读取第一个元素
    ElemType x;
    scanf("%d", &x);

    //3. 初始化节点变量，
    LinkList s;
    //4. 使用循环插入数据
    while(x!=9999){
        //4.1 分配一组空间
        s=(LinkList)malloc(sizeof(LNode));
        s->data=x;

        //4.2 在L和s中间插入新节点，称为头插法
        s->next=L->next;//先将s指向nullptr（尾部）
        L->next=s;      //再将L指向s

        scanf("%d", &x);
    }
}

/*
尾插法新建链表；因为要修改链表，所以需要加引用
*/
void list_tail_insert(LinkList &L){
    //1. 申请头节点的空间，并初始化为nullptr
    L = (LinkList)malloc(sizeof(LNode));
    L->next=nullptr;

    //2. 初始化数据变量，并读取第一个数据
    ElemType x;
    scanf("%d", &x);

    //3. 初始化节点变量，同时还要初始化一个尾节点
    LinkList s;
    LinkList r=L;

    //4. 使用循环插入节点
    while(x!=9999){
        //4.1 分配空间并插入数据
        s=(LinkList)malloc(sizeof(LNode));
        s->data=x;

        //4.2 在s后面插入新节点，称为尾插法
        r->next=s;//第一次时r等同于L，所以此时是将头节点指向了s
        r=s;      //下一次时r等同于s，所以下一次s替代了L作为新的“头节点”

        scanf("%d", &x);
    }

    //5. 循环结束后，要将尾节点r指向nullptr
    r->next=nullptr;
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
读取链表的第i个位置的元素，返回指向该结构的指针；位置从1开始
*/
LinkList IndexElem(LinkList L, int SearchPos){
    //1. 先判断搜索的位置的合法性
    if(SearchPos<0)
        return nullptr;
    //2. 头节点不存放元素，但是部分情况下需要使用头节点
    if(SearchPos==0)
        return L;

    //3. 通过遍历链表判断位置，同时检查L是否为空指针
    int i;
    for(i=0; L&&i<SearchPos; i++)
        L=L->next;

    return L;
}
/*
按值查找链表中的元素，返回元素所在的节点对应的指针
*/
LinkList ValueElem (LinkList L, ElemType SearchVal){
    //1. 头节点没有元素，所以直接跳至下一个节点
    L=L->next;
    //2. 通过遍历链表查找元素，可以使用两个条件进行循环，
    while(L&&L->data!=SearchVal)
        L=L->next;
    return L;
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

/*
按照位置在列表中插入元素，接受一个需要插入的值，和该元素最终存放的位置（从1开始）
*/
bool ListInsert(LinkList L, int i, ElemType InsertVal){
    //1. 新建一个指针，并指向需要插入的位置的上一个节点
    LinkList p = IndexElem(L, i-1);

    //2. 通过查找元素函数，判断插入的位置是否合法（上一个节点中的指针不能为空）
    if(nullptr==p)
        return false;

    //3. 新建一个指针，然后分配空间并赋值
    LinkList q = (LinkList)malloc(sizeof(LNode));
    q->data=InsertVal;

    //4.
    q->next=p->next; //将上一个节点指向的节点，赋值给这个新的节点
    p->next=q;       //将上一个节点指向这个节点

    return true;
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
    pre->next->prior=ins; //将上一个节点的原来的下一个节点，的头指针指向新插入的节点
    ins->prior=pre;       //新插入的节点的头指针指向上一个节点
    pre->next=ins;        //将上一个节点指向新节点

    return true;
}

/*
删除给定位置的节点，位置从1开始
*/
bool ListDelete(LinkList L, int i){
    //1. 初始化一个指针，并通过查找函数将其赋值为需要删除的节点的前一个节点
    LinkList p= IndexElem(L, i-1);

    //2. 判断位置是否合法
    if(NULL==p)
        return false;

    //3. 将需要删除的节点记录下来
    LinkList q=p->next;
    //4. 将需要删除的节点指向的节点，赋值给上一个节点的尾指针
    p->next=q->next;

    //5. 最后需要释放删除的节点的空间
    free(q);

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


void print_linked_list(LinkList L){
    //头指针不存放数据，所以直接读取下一个节点
    L=L->next;
    //通过循环遍历链表
    while(nullptr!=L){
        printf("%3d", L->data);
        L=L->next;
    }
    putchar('\n');
}



//考研真题实战

/*
 * 查找链表的中间位置，然后将这个中间节点赋值给新的头节点L2，
 * （此处将L2作为参数，也可以将L2作为返回值）
 */
void find_middle(LinkList L, LinkList &L2){
    //1. 给第二条链表的头节点分配空间
    L2 = (LinkList)malloc(sizeof(LNode));

    //2. 新建两个指针，并指向第一个节点
    LinkList pfirst,psecond;
    pfirst=psecond=L->next;

    //3. 开启循环，条件为pfirst不为空值
    while(pfirst!=nullptr){
        //3.1 走第一步
        pfirst=pfirst->next;
        //3.2 判断下一步是否依旧合法，不合法时停止
        if(pfirst==nullptr)
            break;
        //3.3 走第二步
        pfirst=pfirst->next;
        //3.4 判断下一步是否依旧合法，保证偶数个节点时，psecond能够指向前一个节点
        if(pfirst==nullptr)
            break;

        //3.5 第二个指针一次走一步
        psecond=psecond->next;
    }

    //4. 将后一段的第一个节点赋值给新的头节点L2
    L2->next=psecond->next;
    //5. 将前一段链表的尾节点设置为null
    psecond->next=nullptr;
}

/*
 * 使用三个指针反转给定的链表，加入了end参数，遍历到end指针后就停止；
 * 可以使用IndexElem定位需要的节点
 * 可以设置一个尾节点，并将返回值修改为尾节点，便于后续利用
 */
void reverse(LinkList L, LinkList end){
    //1. 初始化三个指针，都赋值给第一个节点
    LinkList r,s,t;
    r=s=t=L->next;

    if(end)//逆置后的节点少了一个；因为逆置时是不包括将nullptr和最后一个节点逆置这一步的
           //所以需要额外加一步，但应注意指针为空的判断
        end=end->next;

    //2. 判断链表是否没有元素（第一个节点为空）
    if(nullptr==r)
        return;
    //3. 走一步，判断链表是否只有一个元素（不需要逆置）
    s=r->next;
    if(nullptr==s)
        return;

    //4. 走第二步，并开启循环，结束条件为t为nullptr
    t=s->next;
    while(t!=end){
        //4.1 将s指向r，从而逆置这两个节点
        s->next=r;

        //4.2 三个指针同时向后走一步，应注意顺序
        r=s;
        s=t;
        t=t->next;
    }

    //5. t走到nullptr后循环就结束了，所以还需要将最后两个节点逆置
    s->next=r;

    //6. L->头节点->第一个节点需要指向nullptr
    L->next->next=nullptr;
    //7. L->头节点指向s（新的第一个节点）
    L->next=s;
}

/*
 *两个一组，交换链表中的节点
 */
void swap_pairs(LinkList L){
    //1.
    LinkList x,y,z;
    x=y=z=L->next;
    LinkList tmp=L->next->next;//多用了一个指针来存储节点2

    //2.
    if(x== nullptr)
        return;
    y=x->next;
    //3.
    if(y== nullptr)
        return;

    //4.
    z=y->next;
    while(z){
        //4.1 由于一次走两步，所以此处有两种可能，z的下一个节点可能是nullptr
        if(z->next==nullptr){
            y->next=x;//逆置x、y节点仍然可以做
            break;    //但不能再将x赋值给z->next了，也不能再前进了，需要直接跳出循环
        }

        //4.2
        y->next=x;
        x->next=z->next;//存在一个细节问题，第一次变更时，节点1已经指向节点4了，
                        //所以最后返回头节点时，头节点->节点1->next也是节点4；即节点1，2被漏掉了

        //4.3
        x=z;
        y=z->next;
        z=z->next->next;//由于前进步骤放在最后，所以不用担心z走到nullptr，因为这样不会再进入下一轮循环
    }

    //5.
    y->next=x;
    x->next=z;//5.1 此处理论上可以不加判断
    // 如果z还存在（尾节点），即总共有奇数个节点，则将x指向z
    //如果z已经是nullptr了，同样可以将x指向z（nullptr），

//    if(z){
//        x->next=z;
//    }else{
//        x->next=nullptr;
//    }

    L->next=tmp;
}

/*
 * 根据两个链表的头节点，（交替）合并两个链表
 */
LinkList merge(LinkList L1, LinkList L2){
    //1.
    LinkList tail,one,two;

    //2.
    if(L1->next== nullptr)
        return L2;
    tail=L1->next;
    if(tail->next==nullptr){
        L1->next=L2->next;
        L2->next=L1;
    }
    one=tail->next;
    if(L2->next== nullptr)
        return L1;
    two=L2->next;

    //3.
    while(one&&two){
        tail->next=two;
        tail=two;
        two=two->next;

        tail->next=one;
        tail=one;
        one=one->next;
    }

    //4.
    if(one!= nullptr){
        tail->next=one;
    }else{
        tail->next=two;
    }
    return L1;
}

/*
 * 合并两个有序（升序）链表，返回新的有序链表的头节点
 */
LinkList merge_sorted_list(LinkList L1, LinkList L2){
    //1.
    LinkList L;
    L = (LinkList)malloc(sizeof(LNode));

    //2.
    LinkList tail,one,two;
    one=L1->next;
    two=L2->next;
    tail=L;

    //3.
    while (one&&two){
        if(one->data > two->data){
            tail->next=two;
            tail=two;
            two=two->next;
        }else{
            tail->next=one;
            tail=one;
            one=one->next;
        }
    }

    //4.
    if(one!= nullptr){
        tail->next=one;
    }else{
        tail->next=two;
    }

    //5.
    return L;
}

int main() {
    LinkList L1;
    list_tail_insert(L1);
    //示例：输入3，4，5，6，7，9999
    print_linked_list(L1);

//    ListInsert(L1, 6, 8);
//    ListInsert(L1, 7, 9);
//    ListInsert(L1, 1, 2);
//    print_linked_list(L1);


    LinkList L2;
    list_tail_insert(L2);
    print_linked_list(L2);

    LinkList L;
    L= merge(L1,L2);
    print_linked_list(L);
//    reverse(L1, IndexElem(L1, 10));
//    print_linked_list(L1);

//    LinkList L2;
//    list_tail_insert(L1);
//    //示例：输入3，4，5，6，7，9999
//    print_linked_list(L1);

/*
    if(IndexElem(L1, 10)){
        printf("%3d", IndexElem(L1, 10)->data);
    }

    if(ValueElem(L1, 98)){
        printf("%3d", ValueElem(L1, 98)->data);
    }
*/


/*
    ListFrontInsert(L1, 2, 20);
    ListDelete(L1,2);
    print_linked_list(L1);
*/



    return 0;
}
