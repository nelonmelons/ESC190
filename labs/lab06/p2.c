#include <stdio.h>
#include <stdlib.h>
#include "p1.h"

int validate(LL *L){
    int i = 0;
    node *cur = L->head;
    while (cur){
        cur = cur->next;
        i++;
    }
    if (i == L->size){
        return 1;
    }
    return 0;
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
    printf("%i", validate(L));
    return 0;
}