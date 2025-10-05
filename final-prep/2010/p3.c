#include <stdio.h>
#include <stdlib.h>

void dutch(int *list, int size){
    int zero = 0;
    int one = 0;
    int two = 0;
    for (int i = 0; i < size; i++){
        if (list[i] == 0){
            zero++;
        }
        else if (list[i] == 1){
            one++;
        }
        else{
            two++;
        }
    }
    for (int i = 0; i < zero; i++){
        list[i] = 0;
    }
    for (int i = zero; i < one; i++){
        list[i] = 1;
    }
    for (int i = one; i < two; i++){
        list[i] = 2;
    }
    return list;
}