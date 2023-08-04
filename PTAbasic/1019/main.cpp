#include <stdio.h>
#include <algorithm>

int compare(int a, int b){
    {return a>b;}
}

void print_array(int *ar, int len){
    for (size_t i = 0; i < len; i++)
    {
        printf("%d", ar[i]);
        //putchar(' ');
    }
    putchar('\n');
}

int numlength (int num){
    int i = 0;
    while (num) {
        num = num / 10;
        i++;
    }
    return i;
}

void seperate_num(int *&sep, int num, int length) {
    sep = (int *)malloc(length * sizeof(int));

    for (size_t i = length - 1; num; i--)
    {
        sep[i] = num % 10;
        num = num / 10;
    }
}


void seperate_numb(int *&p, int num) {
    static int sep[4] = {0};
    for (size_t i = 3; num; i--)
    {
        sep[i] = num % 10;
        num = num / 10;
    }
    p = sep;
}

int combine_num(const int *arr, int length){
    int result = 0;
    int base = 1;
    for (size_t i = length-1; i > 0; i--)
    {
        result = result + arr[i] * base;
        base = base * 10;
    }
    result = result + arr[0] * base;

    return result;
}


int main (void){
    int num;
//    scanf("%d", &num);

    int* p = nullptr;
    seperate_num(p, 10831, 5);
    print_array(p,5);
    free(p);

    return 0;
}