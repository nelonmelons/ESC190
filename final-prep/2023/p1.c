#include <stdio.h>
#include <stdlib.h>

double fact(int n){
    double res = 1;
    for (int i = 1; i <= n; i++){
        res = res * i;
    }
    return res;
}

int main(void){
    printf("%f\n", fact(20)
    );
    
}

//runtime complexity: O(n) (assuming mulitplication for large ints is constant)