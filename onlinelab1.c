/*Q0 (not graded)
===========
Make sure that you can run and compile a Hello World program in VS Code.
Q1
===
Write the function 

int linear_search(int *a, int sz, int elem)

The function returns the index of the first occurrence of the element elem in a block of ints a of size sz. Assume elem occurs in a.

Q2
====
Write the following function, which reverses the block of ints arr, which is of size sz. For example, if arr starts out as {5, 6, 7, 8}, it should become {8, 7, 6, 5}

void reverse_arr(int *arr, int sz)
*/
#include <stdio.h>

int linear_search(int *a, int sz, int elem){
    for (int i = 0; i < sz; i++){
        if (a[i] == elem){
            return i;
        }
    }
    return -1;
}
void reverse_arr(int *arr, int sz){
    int start = 0;
    int end = sz - 1;
    int temp;
    while (start < end){
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
