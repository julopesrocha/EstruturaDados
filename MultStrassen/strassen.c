#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
/* gcc strassen.c -o strassen */
int **A;
int **B;
int **C;

void inicializaMatriz(int n);
int **alocaMatrizes(int n);
void printMatriz(int **M, int n);

int main(){
    int n;
    
    // Recebe a dimensão das duas matrizes a serem geradas
    printf("Informe o tamanho N das 2 matrizes N x N para serem geradas: ");
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

    // aloca & incializa matrizes com valores aleatórios
    inicializaMatriz(n);

    // print das matrizes geradas
    printf("Matriz A\n");
    printMatriz(A, n);

    printf("Matriz B\n");
    printMatriz(B, n);

    return n;
}

void inicializaMatriz(int n){
    // inicializa as matrizes
    A = alocaMatrizes(n);
    B = alocaMatrizes(n);
    C = alocaMatrizes(n);

    // Vamos usar l => linha e c => coluna
    for(int l = 0; l < n; l++){
        for(int c = 0; c < n; c++){
            A[l][c] = rand()%100;
            B[l][c] = rand()%100;
        }
    }
}

int **alocaMatrizes(int n){
    int **temp = (int **) malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++){
        temp[i] = (int *) malloc(n * sizeof(int));
    };
    return temp;
}

void printMatriz(int **M, int n) {
    for(int l = 0; l < n; l++){
        for(int c = 0; c < n; c++){
            printf("%d ", M[l][c]);
        }
        printf("\n");
    }
    printf("\n");
}