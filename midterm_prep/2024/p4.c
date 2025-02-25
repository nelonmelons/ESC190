#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    int marks[10];
    char student_number[11];
} student;

//Write a function that takes in the name of the file, and prints the student numbers of all the student(s)whose average mark is the highest. (There can be one or more such student)
void read_all_students(char *filename){
    FILE *f = fopen(filename, 'r');
    char line[100];
    //interate through all students in file and create block of em
    //first determine size
    int sz = 0;
    while (fgets(line, sizeof(line), f)){
        sz++;
    }
    rewind(f);
    student *block = (student *)malloc(sizeof(student) * sz);

    int i = 0;
    double highestavg = 0;
    char *higheststudents[11] = (char *)malloc(sz * 11 * sizeof(char));

    while (fgets(line, sizeof(line), f)){
        strncpy(block[i].student_number, line, 10);
        block[i].student_number[11] = '\0';
        char *ptr = line + 11;
        int markindex = 0;
        while (*ptr != ' ' && *ptr != '\n'){
            block[i].marks[markindex] = atoi(ptr);
            markindex++;
            ptr+=2;
            if (*ptr == ' '){
                ptr++;
            }
        }
        i++;
        //calc avg
        int sum = 0;
        int j = 0;
        while (block[i].marks[j] != NULL){
            sum += block[i].marks[j];
            j++;
        }
        double avg = sum/j;
        if (avg >= highestavg){
            highestavg = avg;
        }
    }
    for (int k = 0; k < sz; k++){
        double sum = 0;
        int count = 0;
        while (block[k].marks[count] != NULL){
            sum += block[k].marks[count];
            count ++;
        }
        double avg = sum/count;
        if (avg == highestavg){
            printf("%s\n", block[k].student_number);
        }
    }
    free(block);
    fclose(f);
}