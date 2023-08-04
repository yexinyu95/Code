#include<stdio.h>

int main (void)
{
//  initialize array
    int  numberarray[3];
    char chararray[3];

//  fill the array
    numberarray[0] = 0;    
    numberarray[1] = 1;    
    numberarray[2] = 2;
//  extra (or wrong) assign won't make sense in numberarray
    numberarray[3] = 3;

    chararray[0]   = 'a';
    chararray[1]   = 'b';
    chararray[2]   = 'c';
//  extra assign won't make sense in chararray 
    chararray[37]   = 'd';

//  but wrong assign will cause 'stack smashing'
//    chararray[3]   = 'd';


/*  
    check array elements with index
    int i;
    printf("input a number in [0, 3]: ");
    scanf("%d", &i);
*/


    printf("the %d element of numberarray is %d. \n", 2, numberarray[2]);
    printf("the %d element of chararray is %c. \n", 3, chararray[3]);

    return 0;
}