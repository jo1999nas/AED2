#include <stdio.h>

// Função para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função recursiva para gerar as permutações
void permutar(int A[], int atual, int fim) {
    // Se chegou ao fim, imprime a sequencia
    if (atual == fim) {
        for (int i = 0; i <= fim; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    } else {
        // Vamos percorrer o vetor
        for (int i = atual; i <= fim; i++) {
            // Primeiro fazemos uma troca
            trocar(&A[atual], &A[i]);
            // Testamos as outras permutações
            permutar(A, atual + 1, fim);
            // Por fim desfazemos a troca (backtracking)
            trocar(&A[atual], &A[i]);
        }
    }
}

// Função principal
int main() {
    int A[] = {1, 2, 3}; // Vetor de exemplo
    int n = sizeof(A) / sizeof(A[0]); // Calcula o tamanho do vetor

    printf("Permutacoes do vetor:\n");
    permutar(A, 0, n - 1);

    return 0;
}
