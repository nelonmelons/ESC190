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
void LL_append(LL *my_list, int new_elem){
    node *n;
    n = (node *)malloc(sizeof(node));
    n->data = new_elem;
    n->next = NULL;
    if (my_list->head == NULL){
        my_list->head = n;
        my_list->size++;
    }
    else{
        node *cur = my_list->head;
        while (cur->next != NULL){
            cur = cur->next;
        }
        cur->next = n;
        my_list->size++;
    }
}