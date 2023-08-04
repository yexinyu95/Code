#include <cstdio>

int main() {
    short i = 0x8011;
    short j;
    j=i<<1;

    unsigned short r = 0x8011;
    unsigned short s;
    s=r<<1;

    int k=1;
    int total=0;
    do{
        total+=k;
        k++;
    }while(k<=100);


    int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    printf("sizeof arr = %3d\n", sizeof(arr));
    printf("arr[2][3]=%d\n", arr[2][3]);

    int x=10;
    int *p=&x;
    int **p2=&p;
    int y=**p2;

    return 0;
}
