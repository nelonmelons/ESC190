#include <stdio.h>
#include <stdlib.h>

typedef struct daylight{
    int hours;
    int minutes;
} daylight;

void create_daylight_pt_block(daylight ***block, int *data, int n){
    *block = (daylight**)malloc((n/2) * sizeof(daylight *));
    for (int i = 0; i < n/2; i++){
        (*block)[i] = (daylight*)malloc(sizeof(daylight));
        (*block)[i]->hours = data[i * 2];
        (*block)[i]->minutes = data[i * 2 + 1];
    }
}

// Part (b) [2 marks]
// On March 7, 2023, the day length in Toronto is 11 hours and 29 minutes. During the solar equinox on
// March 20, 2023, the day length in Toronto will be 12 hours and 9 minutes.
// Write code which uses create_daylight_pt_block to store the day lengths of the two days. The data
// in the created structure must be accessible for later use.

int main(void){
    int data[] = {11, 29, 12, 9};
    daylight **block;
    create_daylight_pt_block(&block, data, 4);

    //part c
    printf("%i\n", block[1]->hours);
}

// Part (c) [3 marks]
// Write code that prints out the number of hours in the second (i.e., at index 1) element of the block.

