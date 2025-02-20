#include <stdio.h>
#include <stdlib.h>

// // Complete here: write the function f
// void f(int *n){
//     *n = 42;
//     return;
// }

// int main()
// {
//     int a = 0;
//     int *p = &a;
//     f(p); // a should now be 42
//     printf("%d", a);
//     return 0;
// }

//part b
//Write a function that computes the sum of the odd elements of an array of integers.

// Complete here: write the function sum_odd

// int sum_odd(int *arr, int n){
//     int res = 0;
//     for (int i = 0; i < n; i++){
//         if ((arr[i]%2) != 0){
//             res += arr[i];
//         }
//     }
//     return res;
// }
// int main(void){
//     int arr[] = {4, 3, 2, 1, 5};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     printf("%d\n", sum_odd(arr, n)); // complete the call.
//     // should print 9,
//     // since 3 + 1 + 5 = 9
//     return 0;
// }

// Complete this code so that the values of arr are printed in increasing order, separated by commas, but so
// that the values of arr remain unchanged. Your code should work for any values of elements of arr.

int cmp(const void *a, const void *b) // don’t need to copy this if used
{
    return (*(int*)a - *(int*)b);
}
void g(int *arr, int n){
    int *tmp = (int *)malloc(n * sizeof(int));  // Allocate memory dynamically
    for (int i = 0; i < n; i++){
        tmp[i] = arr[i];
    }
    qsort(tmp, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++){
        printf("%i", tmp[i]);
        if (i < n-1){
            printf(", ");
        }
    }
    printf("\n");
    free(tmp);  // Now free() is correct since tmp was malloc'd
}
int main(){
    int arr[] = {4, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    g(arr, n); // should print out 2, 3, 4
                // but arr is still {4, 2, 3}
    return 0;
}

