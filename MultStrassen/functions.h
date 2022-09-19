#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
/* gcc strassen.c -o strassen */
int **A;
int **B;
int **C;
double strassenTime = 0.0;
double multiNormal = 0.0;


void inicializaMatriz(int n);
int **alocaMatriz(int n);
void printMatriz(int **M, int n);

int geraMatrizes(){
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
    A = alocaMatriz(n);
    B = alocaMatriz(n);
    C = alocaMatriz(n);

    // Vamos usar l => linha e c => coluna
    for(int l = 0; l < n; l++){
        for(int c = 0; c < n; c++){
            A[l][c] = rand()%10;
            B[l][c] = rand()%10;
        }
    }
}

int **alocaMatriz(int n){
    // Nessa função alocamos espaço para cada matriz e seus elementos
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

// Vamos utilzar as funções add para realizar a soma entre matrizes e a função subtrai
int** add(int **M1, int **M2, int n){
    int **temp = alocaMatriz(n);
    for(int l = 0; l < n; l++){
        for(int c = 0; c < n; c++){
            temp[l][c] = M1[l][c] + M2[l][c];
        }
    }
    return temp;
}

int **subtract(int **M1, int **M2, int n){
    int **temp = alocaMatriz(n);
    for(int l = 0; l < n; l++){
        for(int c = 0; c < n; c++){
            temp[l][c] = M1[l][c] - M2[l][c];
        }
    }
    return temp;
}

// Multiplicação de matrizes Strassen

int **strassenMulti(int **A, int **B, int n){
    clock_t begin = clock();
    int** C = alocaMatriz(n);
    int k = n/2;

    if(n == 1){
        int** C = alocaMatriz(1);
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    else{
        int **A11 = alocaMatriz(k);
        int **A12 = alocaMatriz(k);
        int **A21 = alocaMatriz(k);
        int **A22 = alocaMatriz(k);
        int **B11 = alocaMatriz(k);
        int **B12 = alocaMatriz(k);
        int **B21 = alocaMatriz(k);
        int **B22 = alocaMatriz(k);

        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][k+j]; 
                A21[i][j] = A[k+i][j];
                A22[i][j] = A[k+i][k+j];
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][k+j];
                B21[i][j] = B[k+i][j];
                B22[i][j] = B[k+i][k+j];
            }
        }


		int** P1 = strassenMulti(A11, subtract(B12, B22, k), k);
		int** P2 = strassenMulti(add(A11, A12, k), B22, k);
		int** P3 = strassenMulti(add(A21, A22, k), B11, k);
		int** P4 = strassenMulti(A22, subtract(B21, B11, k), k);
		int** P5 = strassenMulti(add(A11, A22, k), add(B11, B22, k), k);
		int** P6 = strassenMulti(subtract(A12, A22, k), add(B21, B22, k), k);
		int** P7 = strassenMulti(subtract(A11, A21, k), add(B11, B12, k), k);

		int** C11 = subtract(add(add(P5, P4, k), P6, k), P2, k);
		int** C12 = add(P1, P2, k);
		int** C21 = add(P3, P4, k);
		int** C22 = subtract(subtract(add(P5, P1, k), P3, k), P7, k);

		for(int i = 0; i < k; i++) {
		    for(int j = 0; j < k; j++) {
		        C[i][j] = C11[i][j];
		        C[i][j+k] = C12[i][j];
		        C[k+i][j] = C21[i][j];
		        C[k+i][k+j] = C22[i][j];
		    }
		}
    }
    clock_t end = clock();
    strassenTime += (double)(end - begin)/CLOCKS_PER_SEC;
    return C;

}
    
    