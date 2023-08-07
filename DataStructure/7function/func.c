//
// Created by abcqa on 2023/4/5.
//

#include "func.h"

int print_star(int i){
    printf("************\n");
    printf("print star %d\n", i);
    return i + 3;
}

void print_message()
{
    printf("function example.\n");
    print_star(6);
}


//recursion examples
int factorial(int num){
    if (num == 1){
        return 1;
    }
    else{
        return num * factorial(num-1);
    }
}

int step(int n){
    if (n == 1 || n == 2){
        return n;
    }
    else{
        return step(n-1)+step(n-2);
    }
}