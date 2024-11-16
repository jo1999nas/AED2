#include <stdio.h>
#include <stdlib.h>

#define N 5

void insertionSort(int vetor[N], int n){
    int i, j, aux;
    // Loop externo que percorre o vetor a partir do segundo elemento
    for(i = 1; i < n; i++){
        aux = vetor[i];     // Copia o valor na posição i para uma variável auxiliar
        j = i - 1;          // Atribui a j a posição anterior a i
        // Loop interno que percorre o vetor de traz pra frente
        while(j >= 0 && vetor[j] > aux){    // Enquanto houverem elementos a esquerda e esse elemento for maior que aux
            vetor[j + 1] = vetor[j];        // Arrasta o elemento maior para a direita
            j--;                            // Decrementa j
        }
        vetor[j + 1] = aux;                 // Coloca aux no lugar correto
    }
}

void insertionSortRecursivo(int vetor[N], int n){
    // Caso base
    if(n <= 1){
        return;
    }

    // Chamada recursiva para ordenar o vetor de tamanho n - 1
    insertionSortRecursivo(vetor,n - 1);

    int aux = vetor[n - 1]; // Aux recebe o ultimo elemento do vetor
    int j = n - 2;          // J recebe o penultimo elemento do vetor

    // Movimentamos os elementos para a direita para abrir espaço
    while(j >= 0 && vetor[j] > aux){    // Enquanto houverem elementos a esquerda e esse elemento for maior que aux
        vetor[j + 1] = vetor[j];        // Arrasta o elemento maior para a direita
        j--;                            // Decrementa j
    }
    vetor[j + 1] = aux;                 // Coloca aux no lugar correto
}

void imprimeVetor(int vetor[N], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
}

int main(){
    int vet[N] = {3, 1, 2, 5, 4};
    insertionSortRecursivo(vet, N);
    imprimeVetor(vet, N);
    return 0;
}
