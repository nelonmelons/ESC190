// In C, write a function that takes in an array of integers and its size, and returns 1 if the array is strictly increasing (e.g., {1, 5, 10, 12}) and 0 otherwise (e.g., {1, 2, 2, 3} or {5, 4}). You must use recursion.
// You must not use loops, global variables, or any helper functions.
// int is_increasing(int *arr, int sz)
// {
#include <stdlib.h>
#include <stdio.h>

int is_increasing(int *arr, int sz){
    // Base case: array of size 1 or less is always increasing
    if (sz <= 1){
        return 1;
    }
    // Check if current element is less than next element
    // and recursively check rest of array
    if (arr[sz-2] >= arr[sz-1]){
        return 0;
    }
    return is_increasing(arr, sz-1);
}

int main(void){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    printf("%i\n", is_increasing(arr,7));
}