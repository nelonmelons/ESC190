#include <stdio.h>
#include <stdlib.h>

int main(void){
    char test[10];
    test[99] = 'd';
    printf("%c", test[9999999]);
}   