#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct student2{
    char *name;
    char *student_number;
    int year;
} student2;

void create_block2(student2 **p_p_s, int num_students){
    *p_p_s = (student2*)malloc(num_students*sizeof(student2));
    for(int i = 0; i < num_students; i++){
        (*p_p_s)[i].name = 0;
        (*p_p_s)[i].student_number = 0;
        (*p_p_s)[i].year = 0;
    }
}
void set_name2(student2 *p_s, char *name){
    int len = strlen(name) + 1;
    p_s->name = (char*)malloc(len * sizeof(char));
    strcpy(p_s->name, name);
}

void  destroy_block2(student2 *p_s){
    while (p_s != NULL) {
    if (p_s->name != NULL) {
        free(p_s->name);
        }
    if (p_s->student_number != NULL) {
        free(p_s->student_number);
        }
    p_s++;
    }
    free(p_s);
}

int main(void){
    student2 *p_students;
    create_block2(&p_students, 3);
    set_name2(&p_students[0], "John Smith");
    printf("Student name: %s\n", p_students[0].name);
    destroy_block2(p_students);
}