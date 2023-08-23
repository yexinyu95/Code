#include <cstdio>
#include <cstdlib>

#define MAXLEN 255
#define N 5

//顺序存储（静态）
typedef struct SString{
    char ch[MAXLEN];
    int length;
}SString;

//顺序存储（动态）
typedef struct DString{
    char* ch;
    int length;
}DString;

/*
三种顺序存储的方式
1. 在结构中新声明一个length变量存储长度
2. 使用ch[0]存储长度，这样保证了字符串下标从1开始；但是由于字符只使用1B存储，所以长度只能为0-255
3. C的方式，在字符串末尾使用`\0`来标记
*/

//链式存储，
//由于1个字符只占1B，为了提高存储密度，可以在一个结构内存储多个字符（字符数组）
typedef struct StringNode{
    char ch[N];
    struct StringNode* next;
}StringNode, *String;


void InitDString(DString S, int length){
    S.ch=(char*)malloc(length*sizeof(char));
    S.length=0;
}

bool SubString(SString &Sub, SString S, int pos, int len){
    
}

int StrCompare(SString A, SString B){
    for (size_t i = 0; i<=A.length&&i<=B.length; i++){
        if(A.ch[i]!=B.ch[i])
            return A.ch[i]-B.ch[i];
    }

    return A.length-B.length;    
}




