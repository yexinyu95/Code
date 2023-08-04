#include <cstdio>

void PrintArray(int arr[], int len){
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[10] = {0};
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &arr[i]);
        if (arr[i] == 0){
            count++;
        }
    }
    if (count == 10){
        printf("0");
        return 0;
    }

    for (int i = 1; i < 10; ++i) {
        if(arr[i]){
            printf("%d", i);
            arr[i]--;
            break;
        }
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < arr[i]; ++j) {
            printf("%d", i);
        }
    }


//    PrintArray(arr, 10);

    return 0;
}
