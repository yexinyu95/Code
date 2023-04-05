#include<stdio.h>

int main(){
    
    //receive an input
    char ch;
    printf("enter a character.\n");
    scanf("%c", &ch);

    //define a char with number 
    char chh = 67;

    //print the number of char
    printf("The code for %c is %o.\n", ch, ch);
    printf("The code for %c is %o.\n", chh, chh);

    return 0;
}
