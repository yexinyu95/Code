#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXSIZE 50

typedef char ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int top;                
    //栈顶指针一般设置为指向栈顶元素
    //也可以将top设置为指向下一个可以存储的位置，此时代码逻辑会有一定变化；做题时应注意
}SqStack;




void InitStack(SqStack &S){
    //定义s.top=-1时栈为空
    //所以初始化步骤为将S.top设置为-1
    S.top=-1;
}

bool StackEmpty(SqStack S){
    return -1==S.top;
}

bool Push(SqStack &S, ElemType x){
   //1. 先判断栈是否已满
   if(S.top==MAXSIZE-1)
       return false;
   
   //2. 入栈
   //先递增指针，再将数据入栈
    S.top++;
    S.data[S.top]=x;

   //可以简写为S.data[++S.top]=x；使用++S.top的意思为先递增，再使用这个值

   return true;
}


bool Pop(SqStack &S, ElemType &m){
    //1. 先判断栈是否为空
    if (StackEmpty(S))
        return false;
    

    //2. 出栈
    //先将数据出栈，然后递减指针
    //“出栈”不会删除原来的数据，只是逻辑上不再使用该数据
    m=S.data[S.top];
    S.top--;

    //可以简写为m=S.data[S.top--]；使用S.top--的意思为先使用值，再递减

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



/*
共享栈，
为了更好的利用内存空间，可以将划分得到的内存从高位和低位设置为两个栈
低位的栈向高位逐个存储，而高位的栈向低位逐个存储
两个栈顶指针即将相遇时定义为栈满
*/
typedef struct ShStack{
    ElemType data[MAXSIZE];
    int topHigh;
    int topLow;
}ShStack;

void InitStack(ShStack &S){
    S.topHigh=MAXSIZE;
    S.topLow=-1;
}

bool StackEmpty(ShStack S){
    return S.topHigh==S.topLow+1;
}

//栈的应用

/*
代码的括号匹配
接受一个字符串变量，返回该字符串中的括号是否能够两两配对
*/
bool bracketCheck(char str[]){
    //1. 
    SqStack S;
    InitStack(S);

    //2. 开启循环，从左依次扫描所有字符
    for (size_t i = 0; i < strlen(str); i++)
    {
        //2.1 将左括号入栈
        if(str[i]=='('||str[i]=='['||str[i]=='{')
            Push(S, str[i]);
        

        else{
            //2.2 有右括号，但是栈（中的左括号）为空
            if(StackEmpty(S))
                return false;

            //2.3 出栈栈顶元素，判断括号是否匹配
            char topElem;
            Pop(S, topElem);
            if(str[i]==')'&&topElem!='(')
                return false;            
            if(str[i]==']'&&topElem!='[')
                return false;
            if(str[i]=='}'&&topElem!='{')
                return false;
        }
    }

    //3. 如果栈为空，则说明所有括号都匹配
    return StackEmpty(S);
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
