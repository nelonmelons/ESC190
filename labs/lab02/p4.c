#include <stdio.h>

int* binary_search_deluxe_left(int *L, int target) {
    static int res[2] = {-1, -1};
    int length = 8;
    int left = 0;
    int right = length - 1;
    
    // Find leftmost occurrence
    while (left <= right) {
        int mid = (left + right) / 2;
        if (L[mid] > target) {
            right = mid - 1;
        }
        else if (L[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
            res[0] = mid;
        }
    }
    
    // Find rightmost occurrence
    left = 0;
    right = length - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (L[mid] > target) {
            right = mid - 1;
        }
        else if (L[mid] < target) {
            left = mid + 1;
        }
        else {
            left = mid + 1;
            res[1] = mid;
        }
    }
    return res;
}

int main(void){
    int arr[] = {1, 2, 3, 10, 10, 10, 12, 12};
    int *res = binary_search_deluxe_left(arr, 10);
    printf("%d %d\n", res[0], res[1]);
}
