#include <stdio.h>

void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz){
    for (int i = 0; i < arr1_sz; i++){
        int correct = 1;
        for (int j = 0; j < arr2_sz; j++){
            if (arr1[i+j] != arr2[j]){
                correct = 0;
            }
        }
        if (correct == 1){
            for (int j = 0; j < arr2_sz; j++){
                arr1[j+i] = 0;
            }
        }
    }
}

int main(void){
    int a[] = {5, 6, 7, 8, 6, 7};
    int b[] = {6, 7};
    seq_replace(a, 6, b, 2);
    for (int i = 0; i < 6; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
// time complexity: O(n^2)