#include <iostream>
#include "stdio.h"
#include "algorithm"

struct mooncake { ;
    float storage, total, price;
};

int compare(mooncake i, mooncake j){
    return i.price > j.price;
}

int main() {
    int number, demand;
    scanf("%d %d", &number, &demand);
//    mooncake* p;
//    p = (mooncake *)malloc(number * sizeof(mooncake));
    mooncake all[1000] = {0};

    for (int i=0; i<number; i++){
        scanf("%f", &all[i].storage);
    };
    for (int j = 0; j < number; ++j) {
        scanf("%f", &all[j].total);
    };

    for (int k = 0; k < number; ++k) {
        all[k].price = all[k].total / all[k].storage;
    };
/*
    for (int i = 0; i < number; ++i) {
        printf("%f ", all[i].price);
    };
*/
    std::sort(all, all+number, compare);

    double revenue = 0;

    for (int i = 0; demand > 0; ++i) {
        if (demand > all[i].storage)
        {
            demand = demand - all[i].storage;
            revenue = revenue + all[i].total;
        }
        else
        {
            revenue = revenue + demand * all[i].price;
            demand = 0;
        }
    }

    printf("%lf", revenue);
    return 0;


}
