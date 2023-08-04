#include <stdio.h>
#include <algorithm>

bool compare(int a, int b){
/*    if (a == 0 || b == 0)
    {
        return 0;
    }
    
    else*/ {return a>b;}
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
    while (num)
    {
        num = num / 10;
        i++;
    }
    return i;
}

void seperate_num(int *&p, int num, int length) {
    int *sep = NULL;
    sep = (int *)malloc(length * sizeof(int));

    for (size_t i = length - 1; num; i--)
    {
        sep[i] = num % 10;
        num = num / 10;
    }
    p = sep;
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

int combine_num(int *arr, int length){
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
    scanf("%d", &num);
    int length = 4;

    int *arr = NULL;
    seperate_numb(arr, num);

//    print_array(arr, length);
//    int test[5] = {1,2,3,4,6};
//    printf("%d\n", combine_num(arr, length));

    
    std::sort(arr, arr+length);
//    print_array(arr, length);
    int smaller = combine_num(arr, length);
//    printf("%04d\n", smaller);

    std::sort(arr, arr+length, compare);
//    print_array(arr, length);
    int bigger = combine_num(arr, length);
//    printf("%04d\n", bigger);

    int different = bigger - smaller;

    printf("%04d - %04d = %04d\n", bigger, smaller, different);


 while (different != 6174 && different != 0)
    {
        int arr[4] = {0};
        for (size_t i = 3; different; i--)
        {
            arr[i] = different % 10;
            different = different / 10;
        };
        
        std::sort(arr, arr+length);
        smaller = combine_num(arr, length);

        std::sort(arr, arr+length, compare);
        bigger = combine_num(arr, length);

        different = bigger - smaller;

        printf("%04d - %04d = %04d\n", bigger, smaller, different);
    }
    
 /* */

    return 0;
}