#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse_words(char *str){
    char *res = (char *)malloc((strlen(str) + 1)*sizeof(char));
    int res_ind = 0;
    int str_ind = strlen(str) - 1;

    while (str_ind >= 0){
        int prev = str_ind; // keep track of previous space 
        while (str_ind >= 0 && str[str_ind] != ' '){
            str_ind--;
        }
        strncpy(res[res_ind], str[str_ind+1], prev - str_ind + 1);
        res_ind += (prev - str_ind);
        res[res_ind] = ' ';
        res_ind++;
    }
    return res;
}



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// go backwards; keep track of last letter; where you're writing to 

char *reverse_word(char *str){
    int ind = strlen(str) - 1;
    int res_ind = 0;
    char *res = (char *)malloc(ind * sizeof(char) + 1);
    while (ind >= 0){
        if (str[ind] == ' '){
            
        }
        ind--;
    }
}