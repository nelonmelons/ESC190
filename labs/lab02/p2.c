#include <stdio.h>

void strcat1(char *destination, const char *source){
    int i = 0;
    while(destination[i] != '\0'){
        i++;
    }
    int j = 0;
    while(source[j] != '\0'){
        destination[i + j] = source[j];
        j++;
    }
    destination[i+j] = '\0';
}
void strcat2(char *destination, const char *source){
    while (*destination) {
        destination++;
    }
    while (*source) {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

int main(void){
    char str1[100] = "This is ", str2[] = "programiz.com";
    strcat2(str1, str2);
    printf("%s", str1);
}