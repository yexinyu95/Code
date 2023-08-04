#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void print_array(int p[], int length){
    for (int i = 0; i < length; ++i) {
        printf("%d ", p[i]);
    }
    putchar('\n');
}

int main() {
    char str[1000];
    scanf("%s", str);


    int count[10] = {0};
    for (int i = 0; i < strlen(str); ++i) {
        for (int j = 0; j < 10; ++j) {
            if (int(str[i]) == j+48){
                count[j] = count[j] + 1;
            }
        }
    }


    for (int i = 0; i < 10; ++i) {
        if (count[i] != 0) {
            printf("%d:%d", i, count[i]);
            putchar('\n');
            }
    }
/**/
    return 0;
}
