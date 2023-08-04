#include <stdio.h>
#include <stdbool.h>

#define TSIZE 50

//basic struct to store data
struct film
{
    char title[TSIZE];
    int  rating;
};
typedef struct film Item;

//node struct to store pointer to next data
struct node
{
    Item   item;
    struct node *next;
};
typedef struct node Node;

//define "List" as a pointer to first data struct
typedef Node * List;

int main (void)
{
    List movies;
    
    return 0;
}






void InitializeList(List *plist);

