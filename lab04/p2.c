
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

double my_atof(const char *str)
{
    int i = 0;
    int sign = 1;
    if(str[i] == "-"){
        sign = -1;
        i++;
    }
    double result = 0;
    while(str[i] >= '0' && str[i] <= '9'){
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.'){
        i++;
        double factor = 0.1;
        while(str[i] >= '0' && str[i] <= '9'){
            result += ((str[i] - '0') * factor);
            factor /= 10;
            i++;
        }
    }
    return result * sign;
}




int main(void){
    FILE *file = fopen("p2.txt", "r");
    if(file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    char line[256];
    double sum = 0.0;
    while (fgets(line, sizeof(line), file)) {
        char *equalsSign = strchr(line, '=');
        if (equalsSign != NULL) {

            char *numStr = equalsSign + 1;

            while (*numStr && isspace(*numStr)) {
                numStr++;
            }

            double value = my_atof(numStr);
            sum += value;
        }
    }

    fclose(file);
    printf("Sum = %.12f\n", sum);

    return 0;
}
