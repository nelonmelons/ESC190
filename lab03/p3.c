#include <stdio.h>
#include <string.h>

typedef struct student1{
    char name[200];
    char student_number[11];
    int year;
} student1;

void set_default_name(student1 *p_s){
    strcpy(p_s->name, "Default Student");
    p_s->year = 0;
}

void set_default_name_wrong(student1 s){
    //wont wokr cuz you dont pass in the address
}

int main(void){
    student1 boi = {"Nelson", "1010940608", 2024};
    set_default_name(&boi);
    printf("%s\n", boi.name);
    printf("%i\n", boi.year);
}