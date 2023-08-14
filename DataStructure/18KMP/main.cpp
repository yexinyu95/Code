#include <cstdio>
#include <cstring>

typedef char* CString;

/*
 * 暴力匹配，查找字符串T是否出现在S中，
 * 如果存在，返回S中T出现的位置（下标），
 */
int Index(CString S, CString T){
    //1.
    int i=1,j=1;

    //2.
    while (i<=S[0]&&j<=T[0]){
        //2.1 如果字符相等，比较下一个字符
        if(S[i]==T[j]){
            ++i;
            ++j;
        }
        //2.2 如果字符不相等，需要回退到最初的字符处
        else{
            i=i-j+2;
            j=1;
        }
    }

    //3.
    if(j>T[0])
        return i-T[0];
    else
        return 0;
}



/*
 * KMP算法的辅助函数，用于计算next数组
 * 理解起来较为困难，最好将代码记住
 */
void get_next(char T[], int next[]){
    int i=1;
    next[1]=0;
    int j=0;

    while (i<T[0]){
        if(j==0||T[i]==T[j]){
            ++i;
            ++j;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
}


/*
 * KMP匹配，查找字符串T是否出现在S中，
 * 如果存在，返回S中T出现的位置（下标），
 */
int KMP(CString S, CString T, int next[], int pos){
    //1.
    int i=pos;//A1
    int j=1;

    //2.
    while (i<=S[0]&&j<=T[0]){
        //2.1 如果字符相等，比较下一个字符
        if(j==0||S[i]==T[j]){//A2 j=0说明回到了开头
            ++i;
            ++j;
        }
        //2.2 如果字符不相等，回退到next数组的位置处
        else{
            j=next[j];//A3
        }
    }

    //3.
    if(j>T[0])
        return i-T[0];
    else
        return 0;
}


int main() {
    //需要匹配的两个字符串
    char S[256];
    char T[10];

    //0位置存储字符串的长度，字符从1开始
    S[0]=strlen("abcabaaabaabcac");
    strcpy(S+1, "abcabaaabaabcac");

    T[0]=strlen("abaabcac");
    strcpy(T+1, "abaabcac");

    int pos;
    pos=Index(S,T);


    //KMP使用的next数组
    int next[10];



    return 0;
}
