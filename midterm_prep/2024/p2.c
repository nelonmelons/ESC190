#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Write a function with the signature int last_occurrence(char *str1, char *str2) that takes in two C
// strings, str1 and str2, and returns the location in str1 where the last occurrence of str2 starts. If str2
// is not found in str1, the function should return -1.
// For example,
// char str1[] = "EngSciEngSciTrackOne";
// char str2[] = "EngSci";
// int res = last_occurrence(str1, str2); // res should be 6, since the last
// // occurrence of "EngSci" starts at index 6
// int last_occurrence(char *str1, char *str2)
// {

int last_occurrence(char *str1, char *str2){
    int len = strlen(str2);
    if (strncmp(str1, str2, len) != 0){
        return -1;
    }
    int n = len;
    while (strncmp(str1+n, str2, len)){
        n += len;
    }
    return n;
}

// Write a recursive function that takes in the strings str1 and str2 and returns the location in str1 where
// the first occurrence of str2 starts. If str2 is not found in str1, the function should return -1.
// You are not allowed to use any loops in your solution. You are not allowed to use any global variables.
// You are not allowed to use any external libraries.
// You are allowed to use helper functions that you implement yourself, as long as they do not use loops,
// global variables, or external libraries.
// You are allowed to define additional parameters for your function.
// char str1[] = "aEngSci EngSci TrackOne";
// char str2[] = "EngSci";
// // the recursive function you define should return 1, since that is the
// // index where the first occurrence of "EngSci" starts

int last_occurrence(char *str1, char *str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int res = -1;
    if (*str2 == '\0'){
        return -1;
    }
    else if (*str1 == *str2){
        return last_occurrence(str1+1, str2+1);
    }
    else{-==
        return last_occurrence(str1+1, str2)
    }
}