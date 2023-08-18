#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct collage{
    int id_num;
    char *NAME;
} college;

typedef struct student{
    int num;
    char name[20];
    char sex;
} stu, *pstu;

typedef int INTEGER;


int main() {
    {
        college STU1;

        int LEN = 1;
        scanf("%d", &LEN);
        STU1.NAME = (char *) malloc(LEN + 1);
        scanf("%s", STU1.NAME);
        puts(STU1.NAME);

        free(STU1.NAME);

    }

    {
        stu s = {1000, "wangle", 'M'};
        pstu p;

        p = &s;

        printf("%d %s %c \n", p->num, p->name, p->sex);
    }

    {
        stu s2[3] = {0};


    }





        return 0;
    }

