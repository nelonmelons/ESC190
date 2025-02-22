#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct LL{
    node *head;
} LL;
// Write a function that returns the length of a linked list. 
int length_LL(LL *list){
    if (list->head == NULL){
        return 0;
    }
    int i = 0;
    node *cur = list->head;
    while (cur != NULL){
        cur = cur->next;
        i++;
    }
    return i;
}

//Write a function that returns the median data point of a linked list. You must use qsort to accomplish this.
//Assume the linked list has an add number of elements, and they are all distinct.

int cmp(const void *a, const void *b){
    int A = *(int *)a;
    int B = *(int *)b;
    return A - B;
}

int median(LL *list){
    int len = length_LL(list);
    int *arr = (int *)malloc(len * sizeof(int));
    node *cur = list->head;
    for (int i = 0; i < len; i++){
        arr[i] = cur->data;
        cur = cur->next;
    }
    qsort(arr, len, sizeof(int), cmp);
    int med = arr[len/2];
    free(arr);
    return med;
}

char *generate_strings(char *alphabet, int k){
    int len = strlen(alphabet);
    for (int i = 0; i < len; i++){
        while (k > 0){
            printf("%s", )
        }
    }
}
