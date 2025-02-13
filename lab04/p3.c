#include <stdio.h>
#include <string.h>

typedef struct student1 {
    char name[3];
    int age;
} student1;

void change_name1_wrong(student1 s)
{
    s.name[0] = 'b';
    // cannot pass in s directly, since you are passing in by value
    // function creates local copy, and any modifications are only local
}

void change_name1_right_a(student1 *p_s)
{
    p_s->name[0] = 'b';
    //works since you are passing in address, and making modifications to memory. changes are reflected in system
}

void change_name1_right_b(student1 *p_s)
{
    strcpy(p_s->name, "newname");
    //same thing 
}

int main(void){
    student1 s1 = {"abc", 20};
    change_name1_right_b(&s1);
    printf("%s\n", s1.name); 
    return 0;
}