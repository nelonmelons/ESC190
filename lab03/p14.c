#include <stdio.h>
#include <stdlib.h>

double compute_average(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 0.0;
    }

    char line[100];
    int sum = 0;
    int count = 0;

    while (fgets(line, sizeof(line), fp)) {
        int num = atoi(line);
        sum += num;
        count++;
    }

    fclose(fp);

    return (double)sum / count;
}

int main() {
    double avg = compute_average("numbers.txt");
    printf("Average: %.2f\n", avg);
    return 0;
}