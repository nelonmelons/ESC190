#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct business {
    int phone_number[10]; // Note: this is an array of 10 integers
    // (one per digit), not a character array
    char *name;
} business;
    
// Question 3. [20 marks]
// You have been tasked with creating a digital White Pages book for the Province of Ontario. You have
// been provided with a text file. The first line of the file contains the number of entries present. Each of the
// following lines contains a phone number formatted as XXX-XXX-XXXX, followed by a tab, followed by
// the business name.
// 3
// 226-222-6678 Spring Cleaning 4 U
// 289-778-1123 Nowruz Party Planners
// 416-445-2555 The April Shower Curtain Company
// Part (a) [15 marks]
// Write a function to read the file filename and set the values at the input pointers appropriately so that
// the information can be used outside the function. The data must be stored as a contiguous block of struct
// business’s.
// Assume memory allocated in this function will be freed elsewhere. Assume that the number of businesses
// can fit in an int. You may not assume that you know the maximum size of a business name. Your code
// needs to be able to handle business names of any length.
// We strongly recommend, but don’t require, using a while-loop rather than strtok or
// sscanf in order to read in the phone numbers and business names. It is MUCH easier to use
// a while-loop!
// typedef struct business {
// int phone_number[10]; // Note: this is an array of 10 integers
// // (one per digit), not a character array
// char *name;
// } business;

void read_numbers(const char *filename, business **whitepages, int *size){
    FILE *f = fopen(*filename, 'r');
    char line[200];
    fgets(line, 200, f);
    line[strlen(line) - 1] = '\0';
}

void read_numbers(const char *filename, business **whitepages, int *size) {
    // Open the file for reading
    FILE *f = fopen(filename, "r");
    if (f == NULL) return;

    // Read the first line to get number of entries
    fscanf(f, "%d\n", size);
    
    // Allocate contiguous block of memory for businesses
    *whitepages = (business *)malloc(*size * sizeof(business));
    
    // Buffer for reading each line
    char line[1000];
    int business_index = 0;
    
    while (fgets(line, sizeof(line), f)) {
        business *current = &(*whitepages)[business_index];
        int phone_index = 0;
        int i = 0;
        
        // Parse phone number
        while (line[i] != ' ') {
            if (line[i] >= '0' && line[i] <= '9') {
                current->phone_number[phone_index++] = line[i] - '0';
            }
            i++;
        }
        
        // Skip whitespace to get to business name
        while (line[i] == ' ' || line[i] == '\t') i++;
        
        // Remove newline if present
        int name_length = strlen(&line[i]);
        if (line[i + name_length - 1] == '\n') {
            line[i + name_length - 1] = '\0';
            name_length--;
        }
        
        // Allocate and copy business name
        current->name = (char *)malloc((name_length + 1) * sizeof(char));
        strcpy(current->name, &line[i]);
        
        business_index++;
    }
    
    fclose(f);
}

//part b
void free_numbers(business *whitepages, int size){
    for (int i = 0; i < size; i++){
        free(whitepages[i].name);
    }
    free(whitepages);
}

