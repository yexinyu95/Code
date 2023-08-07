#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *print_stack()
{
    char c[100] = "I am print_stack func";
    char *p;
    p = c;

    puts(c);
    return p;
}

char *print_malloc(){
    char *p = (char*)malloc(100);
    strcpy(p, "Iam print_malloc func");

    puts(p);
    return p;

}

int main() {
    char *p = print_malloc();
    puts(p);

    free(p);

    return 0;
}
