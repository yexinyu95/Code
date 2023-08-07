#include <cstdio>

#define MaxKey 1000

int hash(const char* key){
    int h=0;
    int g;
    while(*key){
        h=(h<<4)+*key++;
        g=h&0xf0000000;
        if(g){
            h^=g>>24;
        }
        h&=~g;
    }
    return h%MaxKey;//算出来的值非常的大，所以需要通过除法将其转换为可以作为下标的整数
                    //但是这也可能导致“冲突”，
}

void useHash(){
    char* pStr[5]={"xiongda", "lele", "hanmeimei", "wangdao", "feng"};
    int i;
    char* pHash_table[MaxKey]={nullptr};
    for(i=0;i<5;i++){
        printf("%s is key=%d\n", pStr[i], hash(pStr[i]));
        pHash_table[hash(pStr[i])]=pStr[i];
    }
}


int main() {
    useHash();

    return 0;
}
