#include <stdio.h>

void changea(char *p_a){
    *p_a = 10;
    *(p_a + 1) = 23;
}

int main(void){
    char arr[100];
    changea(arr);
}