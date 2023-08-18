#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int size;//代表需要申请的空间的大小

    scanf("%d", &size);//读取需要输入的空间的大小

    char *str;

    str = (char*)malloc(size);

    str[0] = 'H';
    str[1] = 'O';
    str[2] = 'W';
    str[3] = '\0';

//    puts(str);

    strcpy(str, "malloc success");
//    puts(str);

    int *arr;
    arr = (int *)malloc(size * sizeof(int));

    arr[0] = 1;
    arr[1] = 2;

    printf("%d", *arr);


    free(str);

    free(arr);
    return 0;
}
