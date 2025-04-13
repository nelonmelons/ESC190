#include <stdio.h>
#include <stdlib.h>
#include "p1.h"

void delete(LL *L, int i){
    if (L->head == NULL){
        return;
    }
    if (i == 1){
        free(L->head);
        L->head = NULL;  
        return;
    }
    node *cur = L->head;
    for (int j = 0; j < i - 2; j++){
        cur = cur->next;
    }
    node *temp = cur->next;
    cur->next = cur->next->next;
    free(temp);
    L->size--;
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
    delete(L, 2);
    node *cur = L->head;
    while (cur){
        printf("%d\n", cur->data);
        cur = cur->next;
    }
    return 0;
}
