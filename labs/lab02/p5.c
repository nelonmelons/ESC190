#include <stdio.h>
#include <ctype.h>

int my_atoi(char *str){
    int res = 0;
    while (*str){
        if (isdigit(*str)){
            res = res * 10 + (*str - '0');
        }
        str++;
    }
    return res;
}

int main(void)
{
   int val;
   char *str; 
   str = "15086s";
   val = my_atoi(str); 
   printf("integral number = %d", val);
}