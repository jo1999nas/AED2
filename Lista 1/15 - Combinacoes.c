#include <stdio.h>

// Função para gerar combinações
void gerar_combinacoes(int *vetor, int n, int k, int *comb, int indice, int inicio) {
    // Se a combinação está completa, imprime e retorna
    if (indice == k) {
        for (int j = 0; j < k; j++) {
            printf("%d ", comb[j]);
        }
        printf("\n");
        return;
    }
    // O loop percorre o vetor a partir de inicio
    for (int j = inicio; j < n; j++) {
        // O elemento vetor[j] é adicionado no vetor comb na posição do indice
        comb[indice] = vetor[j];
        // A função é chamada recursivamente para preencher o próximo indice com elementos do próximo indice do vetor
        gerar_combinacoes(vetor, n, k, comb, indice + 1, j + 1);
    }
}

int main() {
    int n, k;

    printf("Digite o tamanho do vetor (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Valor inválido para n! Certifique-se de que n > 0.\n");
        return 1;
    }

    int vetor[n];
    // Preenche automaticamente o vetor com valores de 1 a n
    for (int i = 0; i < n; i++) {
        vetor[i] = i + 1;
    }

    printf("Digite o valor de k (tamanho da combinação): ");
    scanf("%d", &k);

    if (k > n || k <= 0) {
        printf("Valores inválidos! Certifique-se de que 0 < k <= n.\n");
        return 1;
    }

    int comb[k]; // Array para armazenar a combinação atual

    printf("Gerando combinações de %d elementos do vetor:\n", k);
    gerar_combinacoes(vetor, n, k, comb, 0, 0);

    return 0;
}
