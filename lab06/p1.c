#include <stdio.h>
#include <stdlib.h>
#include "p1.h"

void append(LL *L, int e){
    node *n = (node *)malloc(sizeof(node));
    n->data = e;
    n->next = NULL;
    if (L->head == NULL){
        L->head = n;
        L->size++;
        return;
    }
    node *cur = L->head;
    while (cur->next){
        cur = cur->next;
    }
    cur->next = n;
    L->size++;
    return;
}

int main(void){
    LL *L = (LL *)malloc(sizeof(LL));
    node *n1 = (node *)malloc(sizeof(node));
    node *n2 = (node *)malloc(sizeof(node));
    n1->data = 5;
    n1->next = n2;
    n2->data = 169;
    n2->next = NULL;
    L->head = n1;
    L->size = 2;
    append(L, 3535);
    node *cur = L->head;
    while (cur){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    return 0;
}