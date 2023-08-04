#include <stdio.h>

int main(void)
{   
/*  initialize pointer */
    
    int *point1;

    point1 = 5;

//  *point1 = 5; is not valid, because pointer is not initilized,
//  printf("*point1 is %d.\n", *point1);

/*  assign a pointer */

    int var1 = 123;
    int var2;
    point1 = &var1;
    var2 = *point1;

    printf("point1 is %p.\n", point1);
    printf("location of var1 is %p.\n", &var1);
    printf("location of var2 is %p.\n", &var2);
    printf("var1 is %d.\n", var1);
    printf("var2 is %d.\n", var2);


/*  assign a pointer directly

//  int *point2 = 1; this is not valid,
    char *point2 = "a";
    printf("point2 is %p.\n", point2);
    printf("*point2 is %c.\n", *point2);
*/

/*  basic operator 
//  this equals change var1 itself,
    *point1 = 23;
    *point1 = *point1 + 1;
    var1 = var1 + 1;
    printf("var1 is %d.\n", var1);
    printf("var1 is %d.\n", *point1);
    printf("location of var1 is still %p.\n", &var1);

//  * operator only assign the 'value' of var1 to var2, 
    printf("var2 is still %d.\n", var2);
    printf("location of var2 is %p.\n", &var2);

//  change pointer itself is 'valid', but always don't make sense,
    point1 = point1 - 1;
    printf("point1 is %p.\n", point1);
    printf("var1's location is %p.\n", &var1);
    printf("*point1 is %d, var1 is %d.\n", *point1, var1); 
*/

    return 0;
}


