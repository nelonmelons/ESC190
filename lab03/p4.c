#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student1{
    char name[200];
    char student_number[11];
    int year;
} student1;

void create_block1(student1 **p_p_s, int n_students){
    *p_p_s = (student1*)malloc(n_students * sizeof(student1));
}

void set_name(student1 *p_s, char *name){
    strcpy(p_s->name, name);
}

void destroy_block1(student1 *p_s){
    free(p_s);
}
int main() {
    student1 *p_s;
    create_block1(&p_s, 5); 
    strcpy(p_s[0].student_number, "1234567890");
    p_s[0].year = 2; 
    set_name(&(p_s[0]), "John");
    printf("%s", p_s[0].name);
    destroy_block1(p_s);
    return 0;
}