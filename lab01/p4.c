#include <stdio.h>
#include <string.h>

void insertionsort(int *arr, int length) {
    for (int i = 1; i < length; i++) {
        int key = arr[i]; 
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; 
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(void){
    int arr[] = {12, 11, 13, 5, 6};
    insertionsort(arr, 5);
    for (int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
