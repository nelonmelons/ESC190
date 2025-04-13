#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count_letters(char *s, int counts[]){
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        int val = s[i] - 'a';
        if (val <= 'a' && val >= 'z'){
            counts[val]++; //assuming counts is originally an array of all 0's
        }
    }   
}

