#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
/* gcc strassen.c -o strassen */
int **A;
int **B;
int **C;

int main(){
    int n;
    
    // Recebe a dimensão das duas matrizes a serem geradas
    printf("Informe o tamanho N das 2 matrizes N x N para serem geradas:  ");
    scanf("%d", &n);
    printf("\n");

    // Verifica se o valor informado é par
    while(n%2 != 0) { 
        printf("Valor inválido! O algoritmo funciona com N sendo par\n");
        printf("Informe o tamanho N das 2 matrizes N x N para serem geradas: ");
        scanf("%d", &n);
        printf("\n");
    };

    printf("Serão geradas 2 matrizes %d x %d de inteiros aleatórios \n", n, n);

    // alloc matrizes
    // print das matrizes geradas
    // printa A

    return n;
}