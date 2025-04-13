#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#if !defined(INTLIST_H)
#define INTLIST_H


typedef struct IntList {
    int *data;
    int size;
    int capacity;
} IntList;



// Allocate memory for an object of type IntList, initialize
// its data to equal the data in data_arr, and set its size
// Store the address of the new object in *p_IntList
void create_list_from_data(IntList **p_IntList, int *data_arr, int size){
    IntList *obj = malloc(sizeof(IntList));
    obj->data = (int *)malloc(size * sizeof(int));
    memcpy(obj->data, data_arr, size * sizeof(int));
    obj->size = size;
    obj->capacity = size;
    *p_IntList = obj;
}   


// Append new_elem to the end of list
void list_append(IntList *list, int new_elem){
    if (list->size == list->capacity){
        list->capacity = list->capacity * 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size] =  new_elem;
    list->size++;
}


// Insert new_elem at index in list. new_elem should now be at
// location index.
// Use the function memmove to move elements of list->data as needed
// If the capacity needs to grow, use realloc to increase the capacity by
// a factor of 2
void list_insert(IntList *list, int new_elem, int index){
    if (list->size == list->capacity){
        list->capacity = list->capacity * 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    memmove(&list->data[index+1], &list->data[index], (list->size - index) * sizeof(int));
    list->data[index] = new_elem;
    list->size++;
}

// Delete the element at index index

void list_delete(IntList *list, int index){
    memmove(&list->data[index], &list->data[index+1], (list->size - index - 1) * sizeof(int));
    list->size--;
    //free(list);
}
// call free as appropriate to free the memory used by list
// Note: the order in which you free list->data and list
// itself is important (how?)
void list_destroy(IntList *list){
    free(list->data);
    free(list->size);
    free(list->capacity);
    free(list);
}

// Return the element at index index in list
int list_get(IntList *list, int index){
    return list->data[index];
}
#endif