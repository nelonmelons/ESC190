#include <stdio.h>

void print_file(char *filename) {
    char line[200];
    FILE *fp = fopen(filename, "r");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);
}

