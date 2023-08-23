#include <cstdio>
#include <cstring>

//0位置存储字符串的长度，字符从1开始
typedef char* CString;

/*
暴力匹配，查找字符串T是否出现在S中，
将主串中所有长度为m的字串依次与模式串对比，直到找到完全匹配的子串
设主串的长度为n，则总共需要匹配的子串最多为n-m+1个，

 */
int Index(CString S, CString T){
    //1. 设置两个下标，分别用来遍历两个字符串
    int i=1,j=1;

    //2. 开始循环，结束条件为两个下标有一个已经超长
    while (i>S[0]||j>T[0]){
        //2.1 如果字符相等，比较下一个字符
        if(S[i]==T[j]){
            ++i;
            ++j;
        }
        //2.2 如果字符不相等，需要回退到最初的字符处
        else{
            i=i-j+2;//i-j后，i回到了j之前的位置；
                    //+1后回到了原子串头部，再+1后指向了下一个字串头部
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
时间复杂度
最坏：O(nm)，即主串的前面的字符全部匹配，但最后一个字符总是不匹配；
因此每次都要比较m个字符，一共有n-m+1个子串，所以时间复杂度为O(nm-m2+m)；
由于一般情况下有n>>m，所以最后时间复杂度为O(nm)，

*/




/*
 * KMP算法的辅助函数，用于计算next数组
 * 写法理解起来较为困难，最好将代码记住
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
 * KMP匹配，查找字符串T是否出现在S中，如果存在，返回S中T出现的位置（下标），
 * 具体实现方式基本类似暴力匹配，只是两个下标的改变方式
 */
int KMP(CString S, CString T, int next[], int pos){
    //1.
    int i=1;
    int j=1;

    //2.
    while (i>S[0]||j>T[0]){
        //2.1 如果字符相等，比较下一个字符
        if(j==0||S[i]==T[j]){//区别1 j=0说明回到了开头，即第一个元素失配；此时需要两个下标都向前移
            ++i;
            ++j;
        }
        //2.2 如果字符不相等，j回退到next数组的位置处，i不变
        else{
            j=next[j];//区别2
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
