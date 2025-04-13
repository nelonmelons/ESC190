#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct student2{
    char *name;
    char *student_number;
    int year;
} student2;

typedef struct student1{
    char name[200];
    char student_number[11];
    int year;
} student1;

void modify_student1(student1 s1) {
    strcpy(s1.name, "Modified");  
}

void modify_student2(student2 s2) {
    strcpy(s2.name, "Modified"); 
}

void modify_student1_ptr(student1 *s1) {
    strcpy(s1->name, "Modified via ptr"); 
}

void modify_student2_ptr(student2 *s2) {
    s2->name = "Modified via ptr"; 
}

int main(void) {
    student1 s1 = {"Original1", "101010101", 2024};
    student2 s2;
    s2.name = (char*)malloc(200 * sizeof(char));
    s2.name = "Original2";

    printf("Before modifications:\n");
    printf("s1.name: %s\n", s1.name);
    printf("s2.name: %s\n", s2.name);

    modify_student1(s1);
    modify_student2(s2);
    printf("\nAfter modifying by value:\n");
    printf("s1.name: %s\n", s1.name);
    printf("s2.name: %s\n", s2.name);

    modify_student1_ptr(&s1);
    modify_student2_ptr(&s2);
    printf("\nAfter modifying by pointer:\n");
    printf("s1.name: %s\n", s1.name);
    printf("s2.name: %s\n", s2.name);

    return 0;
}