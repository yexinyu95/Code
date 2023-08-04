#include <stdio.h>
#define LEN 20

struct names
{
    char first[LEN];
    char last[LEN];
};

struct worker
{
    struct {
    char first[LEN];
    char last[LEN];
    };

    char job[LEN];
    float income;
};

void modify(float *num1);

int main (void)
{
    struct worker fellow[2] = 
    {//struct array(fellow)
        {//struct worker
            {//struct names
            "Ewen", "Villard"},
            "personality coach",
            61111.00
        },
        {
            {"Rod", "Swill"},
            "editor",
            43200.00
        }
    };

    //anonymous struct
    puts(fellow[0].first);

    //pointer initliazation
    struct worker *him;

    //assign struct array's element to pointer
    him = &fellow[0];

    

    printf("%f.\n", (*him).income);

    modify(&((*him).income));
    
    printf("%f.\n", (*him).income);

    return 0;
}

void modify(float *num1)
{
    *num1 = 1111.10;
}

float sum(struct worker stu)
{
    return stu.income + stu.income;
}