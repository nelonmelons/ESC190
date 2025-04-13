#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace_ws(char *s){
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        if (strncmp(s+i, "winter", 6) == 0){
            strncpy(s+i, "summer", 6);
        }
    }
}
int main(void){
    char s[] = "In the winter, I will rest and enjoy the sun. Winter is great! Wait, actually I mean winter.";
    replace_ws(s);
    printf("%s\n", s);
}