#include <stdio.h>

void set_int1(int x)
{
    x = 42;
}
void set_int2(int *p_x)
{
    *p_x = 42;
}

int main(void){
    int a = 2;
    set_int1(a);
    printf("%d\n", a);
    set_int2(&a);
    printf("%d\n", a);
}
//first function takes in value of x 
//second functin takes in address of x and chnages value there to 2