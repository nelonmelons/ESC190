#include <stdio.h>

void changea(int *p_a){
    *p_a = 10;
}

int main(void){
    int a = 5;
    printf("%d\n", a);
    changea(&a);
    printf("%d\n", a);
}