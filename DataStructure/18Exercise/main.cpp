#include <cstdio>

int Median(int a[], int n){
    int pivot;
    int low=0,low0=0;
    int high=n-1, high0=n-1;
    int flag=1;
    int k=n/2;
    int i;

    while(flag) {
        pivot = a[low];
        while (low < high) {
            while (low < high && a[high] >= pivot)
                --high;
            if (low != high)
                a[low] = a[high];
            while (low < high && a[low] <= pivot)
                ++low;
            if (low != high)
                a[high] = a[low];
        }
        a[low] = pivot;
        if (low == k - 1)
            flag = 0;
        else {
            if (low < k - 1) {
                low0 = ++low;
                high = high0;
            } else {
                low = low0;
                high0 = --high;
            }
        }
    }
    return a[k];
}








int main() {
    int A[10]={4,1,12,18,7,13,18,16,5,15};
    int difference;
    difference= Median(A, 10);


    printf("%d", difference);
    return 0;
}
