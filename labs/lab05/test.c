#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "intlist.h"

int main(void){
    int data[] = {10, 20, 30, 40, 50};
    int size = sizeof(data) / sizeof(data[0]);

    IntList *myList = NULL;
    create_list_from_data(&myList, data, size);

    // Verify that the data has been copied correctly.
    printf("List size: %d\n", myList->size);
    for (int i = 0; i < myList->size; i++) {
        printf("%d ", myList->data[i]);
    }
    printf("\n");
    list_insert(myList, 69, 1);
    printf("List size: %d\n", myList->size);
    for (int i = 0; i < myList->size; i++) {
        printf("%d ", myList->data[i]);
    }
    printf("\n");
}