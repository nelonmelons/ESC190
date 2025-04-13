#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct LL{
    node *head;
    int size;
} LL;

// append integer new_elem to linked list my_list
void LL_append(LL *my_list, int new_val, int i){
    node *cur = my_list->head;
    node *n = (node *)malloc(sizeof(node));
    n->data = new_val;
    if (i == 0) {
        n->next = my_list->head;
        my_list->head = n;
    }
    else{
        for (int j = 0; j < i-1; j++){
            cur = cur->next;
        }
        n->next = cur->next;
        cur->next = n;
    }
    my_list->size++;
}
