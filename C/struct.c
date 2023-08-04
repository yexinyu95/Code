#include <stdio.h>
#include <string.h>

char* getstring(char *st, int n);

struct Student
{
	char name[20];
    int age;
    float height;
    float weight;
};

struct salesData
{
//  members of the struct, similar to C,
    unsigned unitsSold;
    double revenue;

//  function type is NOt allowed in C's struct,
//    double avgPrice();
};


int main(void)
{

typedef struct Student Student;

/* initializate at declaration */
    Student studenta = {.name = "Tom",.age = 27};

    studenta.height = 171.7;
    studenta.weight = 61.6;

/*  for user input

    printf("student's name: \n");
    getstring(studenta.name, 20);

    printf("student's age: \n");
    scanf("%d", &studenta.age);
*/


    printf("%s, %d, %.1f\n", studenta.name, studenta.age, studenta.height);
    
    return 0;
}

char *getstring(char *str, int n)
{
    char *str1;
    char *find;

    str1 = fgets(str, n, stdin);
    if (str1)
    {
        find = strchr(str, '\n');
        if (find)
            {*find = '\0';}
        else
            {while (getchar() != '\n')
                continue;
            }
    }

    return str1;
}