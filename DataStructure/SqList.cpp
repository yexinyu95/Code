#include <cstdio>
#define MAXLEN 50

//define a element type
typedef int ElemType;

/* a struct to simulate sequence list
 * has an array to store elements and a int to store length
 */
typedef struct sqlist
{
    ElemType arr[MAXLEN];
    int len;
} sqlist;

void print_sqlist(sqlist L){
    for (size_t i = 0; i < L.len; i++)
    {
        printf("%3d", L.arr[i]);
    }
    putchar('\n');
}


/**
 * insert an element to select list,
 * receive a sqlist, insert element and insert position
 * (need to change the list, so should use refenrence) 
 * return the insert operation's result
*/
bool list_insert(sqlist &L, ElemType ele, int pos){
    //first check whether the sqlist is full,
    if (L.len >= MAXLEN)
    {
        return false;
    }
    //then check whether the position is valid,
    if (pos >= L.len or pos <= 0)
    {
        return false;
    }
    //insert the value
    for (size_t i = L.len; i >= pos; i--)
    {
        L.arr[i] = L.arr[i-1];
    }
    L.arr[pos-1] = ele;

    //add sqlist's length(always forgets&&)
    L.len++;
    return true;
}

int main(void){
    sqlist L;
    for (size_t i = 0; i < 3; i++)
    {
        L.arr[i] = i+1;
    }

    L.len = 3;
    list_insert(L, 60, 2);

    print_sqlist(L);
    return 0;
}


