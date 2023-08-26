#include <stdio.h>
#include <stdlib.h>
#include <vector>

typedef int ElemType;
typedef struct BSTNode{
    ElemType data;
    struct BSTNode *lchild,*rchild;
}BSTNode, *BiTree;

/*
二叉树的建立
*/

//将节点插入二叉搜索树中；接受一个父节点T，和一个需要插入的元素k
bool BST_Insert(BiTree &T, ElemType k){
    //1. 判断是否为根节点，只有第一次时会进行
    if(nullptr==T){
        T=(BSTNode* )calloc(1, sizeof(BSTNode));//分配空间，存储数据
        T->data=k;
        return true;
    }

    //2. 新建两个节点
    BSTNode* p=T;             //用来向下遍历，找到可以存放的节点；初始化为根节点
    BSTNode* parent=nullptr;  //用来存储（可以存放的节点的）父节点；可以初始化为nullptr

    //3. 通过循环寻找节点，结束条件为p为空节点（即p的父节点的子节点可以存）
    while(p){
        //3.1 先存储当前节点，然后再开始遍历
        parent=p;

        //3.2 理论上，二叉排序树不能存储同样的数据，所以此处在遇到同样的值时返回false，
        if(k==p->data)
            return false;
        //3.3 根据大小，判断p向左走还是向右走
        else if(k<p->data)
            p=p->lchild;
        else
            p=p->rchild;
    }

    //4. 将数据存进找到的位置
    //4.1 新建空间，将数据存进去
    BSTNode* treeNode=(BSTNode*)calloc(1, sizeof(BSTNode));
    treeNode->data=k;

    //4.2 返回的是父节点，所以还需要再判断一次大小，确定是存到左侧还是右侧
    if(k>parent->data){
        parent->rchild=treeNode;
        return true;
    }
    else{
        parent->lchild=treeNode;
        return true;
    }

    //(5. 如果走到这里，则说明出现了某些错误)
    return false;
}

//递归方式将节点插入二叉搜索树中
bool BST_Insert_R(BiTree &T, ElemType k){
    //1.
    if(NULL==T){
        T=(BiTree)malloc(sizeof(BSTNode));
        T->data=k;
        T->lchild=T->rchild=NULL;
        return 1;
    }
    //2.
    else if(k==T->data)
        return 0;
    //3.
    else if(k<T->data)
        return BST_Insert_R(T->lchild, k);
    else
        return BST_Insert_R(T->rchild, k);
}

//主函数，构造二叉排序树
BiTree Create_BST(std::vector<ElemType> nums){
    //1. 初始化为nullptr
    BiTree T=nullptr;

    //2. 通过循环将数据逐个插入树中
    ElemType data;
    for (size_t i = 0; i < nums.size(); i++){
        BST_Insert(T, nums[i]);
    }
    
    //3. 返回树根
    return T;
}

//搜索二叉搜索树中的元素
BSTNode* BST_Search(BiTree T, ElemType k, BiTree &parent){
    parent=NULL;
    while(T!=NULL&&k!=T->data){
        parent=T;
        if(k>T->data){
            T=T->rchild;
        }
        else{T=T->lchild;}
    }
    return T;
}

//删除二叉搜索树中的元素
void DeleteNode(BiTree &T, ElemType x){
    //1.
    if(nullptr==T)
        return;

    //2. 通过递归寻找需要删除的节点
    if(T->data > x)//递归时传入的参数为子树，以后也是对子树进行运算，所以不会影响根节点
        DeleteNode(T->lchild, x);
    else if(T->data < x)
        DeleteNode(T->rchild, x);

    //3. 查找到了节点，但是不能直接删除，这样可能会让树断链
    else{
        //3.1 如果左子树为空，可以直接用原节点的右子树替代原节点
        if(T->lchild==nullptr){
            BiTree tempNode = T;
            T=T->rchild;
            free(tempNode);
        }
        //3.2 如果右子树为空，可以直接用原节点的左子树替代原节点
        else if(T->rchild==nullptr){
            BiTree tempNode = T;
            T=T->lchild;
            free(tempNode);
        }

        //3.3都不为空，一般策略为用左子树的最大数据，或右子树的最小数据
        //代替将要删除的节点，再将那个节点的子树连接上
        //这里寻找的是左子树的最右节点
        else{
            //3.3.1
            BiTree tempNode=T->lchild;
            //3.3.2
            while (tempNode->rchild!=nullptr)
                tempNode=tempNode->rchild;
            //3.3.3
            T->data=tempNode->data;
            //3.3.4
            DeleteNode(T->lchild, tempNode->data);
        }
    }
}


/*
二叉树的其它应用
*/

//判断二叉搜索树是否合法（中序遍历法）
void InOrder(BiTree T, std::vector<int> &nums){
    if(NULL!=T){
        InOrder(T->lchild, nums);
        nums.push_back(T->data);
        InOrder(T->rchild, nums);
    }
}
bool isValidBST(BSTNode* root){
    std::vector<int> temp;
    InOrder(root, temp);
    
    for(int i=0;i<temp.size()-1;i++){
        if(temp[i]>=temp[i+1])
            return false;
    }
    return true;
}

//判断二叉搜索树是否合法（递归法）
bool isValidBSThelper(BSTNode* root, long lower, long upper) {
        if (root == nullptr) 
            return true;
        
        if (root->data<=lower || root->data>=upper) 
            return false;
        
        return isValidBSThelper(root->lchild, lower, root->data) && isValidBSThelper(root->rchild, root->data, upper);
    }
bool isValidBST_R(BSTNode* root){
    return isValidBSThelper(root, LONG_MIN, LONG_MAX);
}

//将有序数组转化为平衡二叉搜索树
BSTNode* sortedArraytoBSTHelper(std::vector<ElemType> &nums, int left,int right){
    //1. 
    if(left>right)
        return nullptr;
    //2. 
    else{
        int mid=(left+right)/2;

        auto root=(BSTNode*)malloc(sizeof(BSTNode));
        root->data=nums[mid];

        root->lchild=sortedArraytoBSTHelper(nums, left, mid-1);
        root->rchild=sortedArraytoBSTHelper(nums, mid+1, right);

        return root;
    }
}
BSTNode* sortedArraytoBST(std::vector<ElemType> &nums){
    return sortedArraytoBSTHelper(nums,0,nums.size()-1);
}




int main() {

    std::vector<ElemType> InPut={8,5,9,0,48,8,64,413,98,73,38,63};
    BiTree T=Create_BST(InPut);

    bool valid=isValidBST_R(T);

    return 0;
}
