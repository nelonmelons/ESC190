#include <stdio.h>

int lengthof(char *string){
    int i = 0;
    int counter = 0;
    while (*(string + i) != '\0'){
        counter++;
        i++;
    }
    return counter;
}

int main(void) {
    char *word = "banana";
    int length = lengthof(word);
    printf("%d\n", length);
    return 0;
}
//runtime complexity: O(n)