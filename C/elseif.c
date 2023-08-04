#include <stdio.h>

#define RATE1  0.13
#define RATE2  0.15
#define RATE3  0.30
#define RATE4  0.34


int main(void){
    double kwh;
    double bill;

    printf("input the kwh used: \n");
    scanf("%lf", &kwh);

    if (kwh <= 100){
        bill = RATE1 * kwh;
    }

    else if (kwh <= 200){
        bill = RATE2 * kwh;
    }

    else if (kwh <= 300){
        bill = RATE3 * kwh;
    }

    else{
        bill = RATE4 *kwh;
    }

    printf("the charge for %lf is %lf.\n", kwh, bill);

    return 0;
}