#include <stdio.h>

int main(){

    int resultado;

    for( int i = 1; i <=10; i++){
        for( int j = 1; j <=10; j++){
            resultado = i * j;
            printf(" %d X %d = %d\n", i, j, resultado);

        }
    }
}