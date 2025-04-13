#include <stdio.h>
#include <stdlib.h>

int cmp(int *arr1, int *arr2, int idx, int sz1, int sz2){
    if (sz1 != sz2){
        return 0;
    }
    if (sz1 == idx){
        return 1;
    }
    if (arr1[idx] != arr2[idx]){
        return 0;
    }
    return cmp(arr1, arr2, idx + 1, sz1, sz2);
}

int main(void){
    int arr1[] = {7, 8, 9};
    int arr2[] = {7, 8, 9};
    int arr3[] = {7, 8};
    int res = cmp(arr1, arr2, 0, 3, 3);
    int res2 = cmp(arr1, arr3, 0, 3, 2);
    printf("%i %i\n", res, res2
    );
}