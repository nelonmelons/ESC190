// Write a function with the signature char * strcat_rec(char *dest, const char *src) that concate-
// nates dest and src recursively. The result is to be stored at dest. The function returns the destination
// string dest. The function does the same thing as strcat in string.h. You must use recursion. You
// must not include header files, use helper functions, or use loops. You may assume that there is sufficient
// space at dest to store the resultant string.
#include <stdio.h>
#include <stdlib.h>
char *strcat_rec(char *dest, const char *src){
    if (*dest != '\0'){
        strcat_rec(dest+1, src);
        return dest
    }
    *dest = *src;
    if
        return strcat_rec(&dest+1, &src+1);
    }
}