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
1. 代码的括号匹配
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

/*
2. 数学运算表达式
*/
char* postfix_expression(char infix[]){
    //1.
    int length=strlen(infix);
    auto postfix=(char*)malloc(sizeof(char)*length);
    int pos=0;

    //2. 初始化栈，用于保存“不能确定顺序”的运算符
    SqStack S;
    InitStack(S);
    char temp;

    //3.
    for (size_t i = 0; i < length; i++)
    {
        //3.1 扫描到数字，直接加入表达式
        if(infix[i]<='9'&&infix[i]>='0'){
            postfix[pos++]=infix[i];
        }

        //3.2.1 扫描到左括号，直接入栈
        else if(infix[i]=='('){
            Push(S, infix[i]);
        } 
        //3.2.2 扫描到右括号，依次弹出栈内运算符，并加入表达式，直到弹出左括号
        else if(infix[i]==')'){
            Pop(S, temp);
            postfix[pos++]=temp;
            while (temp!='('){
                Pop(S, temp);
                postfix[pos++]=temp;
            }
        }
        //3.3 扫描到运算符
        else if(infix[i]){}
    }
    
}


int compute(char str[]){
    //1.
    SqStack S;
    InitStack(S);

    //2.
    char tempA,tempB,result;
    int  temp1,temp2,result1;

    //3.
    for (size_t i = 0; i < strlen(str); i++){
        if (str[i]>='0'&&str[i]<='9'){
            Push(S, str[i]);
        }

        else if(str[i]=='+'){
            Pop(S, tempA);
            Pop(S, tempB);
            result=tempA+tempB;
            Push(S, result);
        }
        else if(str[i]=='-'){
            Pop(S, tempA);
            Pop(S, tempB);
            result=tempA-tempB;
            Push(S, result);
        }        
        else if(str[i]=='*'){
            Pop(S, tempA);
            Pop(S, tempB);
            result=tempA*tempB;
            Push(S, result);
        }
        else if(str[i]=='/'){
            Pop(S, tempA);
            Pop(S, tempB);
            result=tempA/tempB;
            Push(S, result);
        }    
    }
}


/*
3. 栈在递归中的应用
函数调用的规律也是后进先出（LIFO），
在函数开始运行之前，操作系统会申请一段空间作为函数调用栈，
主要存储的是函数的返回地址（不会存储函数的代码），函数使用的实参和函数内的局部变量，


*/




int main() {


    return 0;
}
