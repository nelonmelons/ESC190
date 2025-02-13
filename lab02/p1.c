#include <stdio.h>

void set_even_to_zero(int *block, int size){
    for (int i = 0; i < size; i++){
        if (i%2 == 0){
            block[i] = 0;
        }
    }
}

int main(void){
    int block[] = {5, 6, 7, 8};
    set_even_to_zero(block, 4);
    for (int i = 0; i < 4; i++){
        printf("%d ", block[i]);
    }
    printf("\n");
}
