#include <stdio.h>

int my_strcmp_rec(const char* str1, const char* str2){
    if (*str1 == '\0' && *str2 == '\0'){
        return 0;
    }
    if (*str1 != *str2){
        if(*str1 > *str2){
            return 1;
        }
        else{
            return -1;
        }
    }
    return my_strcmp_rec(str1 + 1, str2 + 1);
}

int main() {
  char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
  int result;

  // comparing strings str1 and str2
  result = my_strcmp_rec(str1, str2);
  printf("strcmp(str1, str2) = %d\n", result);

  // comparing strings str1 and str3
  result = my_strcmp_rec(str1, str3);
  printf("strcmp(str1, str3) = %d\n", result);

  return 0;
}
