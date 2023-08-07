#include <stdio.h>

struct student_type1{
    double score;//8个字节
    short age;//2个字节
};
//总共字节数为8*2 = 16

struct student_type2{
    double scoreb;//8个字节
    char height;//1个字节
    short ageb;//1个字节
};
//小的变量可以结合到一起


struct student_type3{

};


int main() {
    struct student_type2 STU1 = {12.1, 'a', 1};


    printf("%d", sizeof(struct student_type2));
    return 0;
}
