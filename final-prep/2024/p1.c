#include <stdio.h>
#include <stdlib.h>

int my_median(int *arr, int sz){
    for (int i = 0; i < sz; i++){
        int counter = 0;
        for (int j = 0; j < sz; j++){
            if (arr[i] <= arr[j]){
                counter++;
            }
        }
        if (counter == sz/2){
            return counter;
        }
    }
}
int main(void){
    int arr[] = {1, 9, 4, 3, 3, 6, 10};
    int res = my_median(arr, 7);
    printf("%i\n", res);
}