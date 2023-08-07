#include <stdio.h>
#include <stdlib.h>

int main() {
//arithmetic operation
    int a = 10, b = 12;
    a = b - a;
    b = b - a;
    a = b + a;
    printf("%d\n%d", a, b);

//pointer arithmetic operation


//bit XOR operation
    int c = 10, d = 12;
    c = c^d;
    d = c^d;
    c = c^d;

//    printf("%d\n%d", c, d);
    return 0;
}
