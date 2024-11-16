#include <stdio.h>
#include <stdlib.h>

void inicializaResultado(int resultado[], int tamanhoResultado){
    for(int i = 0; i < tamanhoResultado; i++){
        resultado[i] = 0;
    }
}

void multiplicaPolinomio(int polinomio1[], int tamanho1, int polinomio2[], int tamanho2, int resultado[]){
    for(int i = 0; i < tamanho1; i++){
        for(int j = 0; j < tamanho2; j++){
            resultado[i + j] += polinomio1[i] * polinomio2[j];
        }
    }
}

void imprime(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(){
    int polinomio1[] = {-2, 4};
    int polinomio2[] = {3, 5};
    int tamanho1 = sizeof(polinomio1)/sizeof(polinomio1[0]);
    int tamanho2 = sizeof(polinomio2)/sizeof(polinomio2[0]);
    int tamanhoResultado = tamanho1 + tamanho2 - 1;
    int resultado[tamanhoResultado];

    inicializaResultado(resultado, tamanhoResultado);
    multiplicaPolinomio(polinomio1, tamanho1, polinomio2, tamanho2, resultado);
    imprime(resultado, tamanhoResultado);

    return 0;
}

