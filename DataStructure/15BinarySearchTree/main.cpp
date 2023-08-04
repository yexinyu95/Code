#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct BSTNode{
    KeyType key;
    struct BSTNode *lchild,*rchild;
}BSTNode, *BiTree;

//一次插入一个节点
int BST_Insert(BiTree& T, KeyType k){
    //新建一个节点，并申请空间
    BiTree NewTree = (BiTree)calloc(1,sizeof(BSTNode));
    //将值赋值给该节点
    NewTree->key=k;

    //如果T是空树，则T是根节点，直接赋值然后结束
    if(NULL==T){
        T=NewTree;
        return 0;
    }

    //新建两个辅助指针，用来查找位置
    BiTree p=T;
    //查找到位置后存储该位置，并将节点存储进树中
    BiTree parent;

    //寻找树中的空节点，判断放到左边还是右边
    while(p){
        parent=p;
        if(k>p->key){
            p=p->rchild;
        }else if(k<p->key){
            p=p->lchild;
        }else{
            return -1;//相等的元素不可以放入查找树
        }
    }

    //将节点放入树中，判断放到左边还是右边
    if(k>parent->key){
        parent->rchild=NewTree;
    }else{
        parent->lchild=NewTree;
    }

    return 0;
}

int BST_Insert_R(BiTree &T, KeyType k){
    if(NULL==T){
        T=(BiTree)malloc(sizeof(BSTNode));
        T->key=k;
        T->lchild=T->rchild=NULL;
        return 1;
    }
    else if(k==T->key)
        return 0;
    else if(k<T->key)
        return BST_Insert_R(T->lchild, k);
    else
        return BST_Insert_R(T->rchild, k);

}

void Create_BST(BiTree& T, KeyType* str, int len){
    T=NULL;
    int i=0;
    for(i=0;i<len;i++){
        BST_Insert(T, str[i]);
    }
}

void InOrder(BiTree T){
    if(NULL!=T){
        InOrder(T->lchild);
        printf("%3d", T->key);
        InOrder(T->rchild);
    }
}

BSTNode* BST_Search(BiTree T, KeyType k, BiTree &parent){
    parent=NULL;
    while(T!=NULL&&k!=T->key){
        parent=T;
        if(k>T->key){
            T=T->rchild;
        }
        else{T=T->lchild;}
    }
    return T;

}

void DeleteNode(BiTree &T, KeyType k){
    if(NULL==T){
        return;
    }
    if(T->key>k){
        DeleteNode(T->lchild, k);
    }else if(T->key<k){
        DeleteNode(T->rchild, k);
    }else{//查找到了节点，但是不能直接删除，这样可能会让树断链
        if(T->lchild==NULL){//如果左子树为空，可以直接用原节点的右子树替代原节点
            BiTree tempNode=T;
            T=T->rchild;
            free(tempNode);
        }else if(T->rchild==NULL){//如果右子树为空，可以直接用原节点的左子树替代原节点
            BiTree tempNode=T;
            T=T->lchild;
            free(tempNode);
        }else{//都不为空，一般策略为用左子树的最大数据，或右子树的最小数据
            //代替将要删除的节点，再将那个节点的子树连接上
            //这里寻找的是左子树的最右节点
            BiTree tempNode=T->lchild;
            while(tempNode->rchild!=NULL){
                tempNode=tempNode->rchild;
            }
            T->key=tempNode->key;//替换将要删除的数据

            DeleteNode(T->lchild, tempNode->key);//传入需要删除的节点的左子树，找到需要删除的节点，然后删除
        }
    }

}

int main() {
    BiTree T;

    KeyType str[] = {10,15,56,25,30,70};
    Create_BST(T,str,6);

    InOrder(T);
    putchar('\n');

    BiTree search,parent;
    search=BST_Search(T,40,parent);


    return 0;
}
