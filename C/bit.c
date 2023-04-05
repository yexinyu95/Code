#include <stdio.h>
#include <stdbool.h>

/* bit field define */
#define RED   4
#define GREEN 2
#define BLUE  1

#define LINE  0
#define DOT   1
#define DASH  2

struct printbox
{
    bool opache  : 1;
    unsigned int color : 3;
    unsigned int style : 2;
};

int main (void)
{
    char ch1 = 'c';
    char ch2 = 'd';

    printf("%d.\n" , (4 & 2));

/* bit field */
    struct printbox box = {true, RED, LINE};
    printf("box settings: %d, %d, %d.\n", box.opache, box.color, box.style);

    box.opache = false;
    box.color  = RED & BLUE;
    box.style  = DOT;

    printf("box settings: %d, %d, %d.\n", box.opache, box.color, box.style);





/*  alignment
    double num1;
    printf("&align: %p.\n", &num1);

    size_t align = _Alignof(double);
    printf("&align: %p.\n", &align);
*/
    return 0;
}