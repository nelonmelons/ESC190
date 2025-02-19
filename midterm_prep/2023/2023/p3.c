#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct business {
    int phone_number[10]; // Note: this is an array of 10 integers
    // (one per digit), not a character array
    char *name;
} business;
    
void read_numbers(const char *filename, business **whitepages, int *size){
    FILE *f = fopen(*filename, 'r');
    char line[200];
    fgets(line, 200, f);
    line[strlen(line) - 1] = '\0';
    
}