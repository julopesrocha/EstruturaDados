#include "functions.h"

int main(int argc, char const *argv[]){
    int n;
    printf("Multiplicação de Matrizes Quadradas\n\n");

    printf("1) Gerar Matrizes\n");
    printf("2) Sair\n\n");
    
    int entrada;
    scanf("%d", &entrada);

    if(entrada == 1){
		n = geraMatrizes();

		printf("Multiplicando...\nResultado:\n\n");
		C = strassenMulti(A, B, n);

		printMatriz(C, n);
    printf("Tempo para multiplicação de Strassen: %f\n", strassenTime);
	}
	else { exit(EXIT_SUCCESS); }

	return 0;    
}