//matrix.c

#include <stdio.h>
#include <stdlib.h>

int get_elem(int **M, int i, int j){
    return M[i][j];
}

void set_elem(int **M, int i, int j, int val){
    M[i][j] = val;
}

int ** new_matrix(int **A, int **B, int m, int n){ /// assume matrix A and matrix B are the same size (i.e. both m xn)
    int **res = (int **)(malloc(m * sizeof(int *)));
    for (int i = 0; i < m; i++){
        res[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++){
            res[i][j] = A[i][j] + B[i][j];
        }
    }
    return res;
}

//matrix.h
//>?????
//main.c
// #include "matrix.h"
// #include <stio,lk......

int main(void){
    int **A = (int **)malloc(2 * sizeof(int *));
    int **B = (int **)malloc(2 * sizeof(int *));
    for(int i = 0; i < 2; i++) {
        A[i] = (int *)malloc(2 * sizeof(int));
        B[i] = (int *)malloc(2 * sizeof(int));
    }
    
    // Initialize A
    A[0][0] = 1;  A[0][1] = -1;
    A[1][0] = 2;  A[1][1] = 0;
    
    // Initialize B
    B[0][0] = -1; B[0][1] = 2;
    B[1][0] = 0;  B[1][1] = 1;
    
    int **res = new_matrix(A, B, 2, 2);
    // Don't forget to free the memory when done
    return 0;
}