#include <stdio.h>

typedef struct student1{
    char name[200];
    char student_number[11];
    int year;
} student1;

void set_default_name(student1 *p_s){
    printf("%s\n", (*p_s).name);
    printf("%s\n", (*p_s).student_number);
    printf("%d\n", (*p_s).year);
}

int main(void){
    student1 boi = {"Nelson", "1010940608", 2024};
    set_default_name(&boi);
    return 0;
}
