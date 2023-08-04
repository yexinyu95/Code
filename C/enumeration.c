#include <stdio.h>

int main (void)
{
    enum spectrum {red, orange, yellow, green, indigo, blue, violet};

/*  another declartion will raise error
    int red = 10; */

    printf("red = %d, orange = %d.\n", red, orange);

//  example of enumeration
    enum spectrum color;
    color = 4;
    printf("blue = %d, purple = %d.\n", color, color + 1);

//  use other numbers
    enum levels {low = 100, medium = 200, high = 300};
    enum levels alevel;

    alevel = 100;
    printf("%d, %d.\n", alevel, low);

    return 0;
}