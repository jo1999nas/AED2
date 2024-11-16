#include <stdio.h>
// vetor = elementos disponiveis para formar a combinação
// n = tamanho do vetor
// k = tamanho das combinações
// comb = vetor que armazena a combinação em construção
// indice = indice atual dentro da combinação em construção
// inicio = indice inicial do vetor para escolher o próximo elemento (evita repetições)
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

    int vetor[n];
    printf("Digite os %d elementos do vetor:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Digite o valor de k (tamanho da combinação): ");
    scanf("%d", &k);

    if (k > n || k <= 0 || n <= 0) {
        printf("Valores inválidos! Certifique-se de que 0 < k <= n.\n");
        return 1;
    }

    int comb[k]; // Array para armazenar a combinação atual

    printf("Gerando combinações de %d elementos do vetor:\n", k);
    gerar_combinacoes(vetor, n, k, comb, 0, 0);

    return 0;
}
