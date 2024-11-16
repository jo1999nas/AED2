#include <stdio.h>
#include <stdlib.h>

void imprime(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// K = numero de digitos
// I = indice atual onde os valores estão sendo atribuidos
void geraBinario(int k, int vetor[], int i){
    if(i == k){
        imprime(vetor, k);
        return;
    }

    // Atribiu 0 na posição i e tenta todas as outras permutações
    vetor[i] = 0;
    geraBinario(k, vetor, i + 1);
    // Atribiu 1 na posição i e tenta todas as outras permutações
    vetor[i] = 1;
    geraBinario(k, vetor, i + 1);
}

int main(){
    int k;
    printf("Insira o valor de K: ");
    scanf("%d", &k);
    int vetor[k];
    geraBinario(k, vetor, 0);
    return 0;
}
