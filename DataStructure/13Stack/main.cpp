#include <cstdio>
#define MAXSIZE 50

typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int top;
}SqStack;


void InitStack(SqStack &S){
    //使用顺序表（数组）实现栈，所以元素下标从0开始；因此定义s.top=-1时栈为空
    //所以初始化步骤为将S.top设置为-1
    S.top=-1;
}

bool StackEmpty(SqStack S){
    if(-1==S.top)
        return true;

    return false;
}

bool Push(SqStack &S, ElemType x){
   //1. 判断栈是否已满
   if(S.top==MAXSIZE-1){
       return false;
   }
   //2. 入栈
   //入栈时要使用++s.top，即先递增，再将数据入栈
    S.data[++S.top]=x;
   /*等价于
    * S.top++;
    * S.data[S.top]=x;
    */
   return true;
}


bool Pop(SqStack &S, ElemType &m){
    //1. 先判断栈是否为空
    if (StackEmpty(S)){
        return false;
    }

    //2. 出栈时要使用s.top--，即先将数据出栈，然后递减
    m=S.data[S.top--];
    /*等价于
     * m=S.data[S.top]
     * S.top--;
     */
    return true;
}

//读取栈顶元素，但是不执行出栈操作
bool GetTop(SqStack &S, ElemType &m){
    if(StackEmpty(S)){
        return false;
    }
    m=S.data[S.top];
    return true;
}


int main() {
    SqStack S;
    InitStack(S);
    bool flag;
    flag = StackEmpty(S);

    if(flag){
        printf("Stack is Empty.");
    }

    Push(S, 3);
    Push(S, 4);
    Push(S, 5);

    ElemType m;
    flag=GetTop(S, m);
    if(flag){
        printf("%d", m);
    }

    flag= Pop(S, m);
    if(flag){
        printf("%d", m);
    }

    return 0;
}
