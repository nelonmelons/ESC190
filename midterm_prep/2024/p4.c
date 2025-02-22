#include <stdio.h>
#include <stdlib.h>

void read_all_students(char *filename){
    FILE *f = fopen(filename, 'r');
    
    char line[100];
    double max_avg = 0;
    
}