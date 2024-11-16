#include <stdio.h>
// n = quantidade de numeros disponiveis
// k = quantidade de digitos da permutação
// seq = vetor com a permutação em construção
// usado = vetor que guarda se um número foi usado na permutação
// indice = indice atual dentro de seq
void gerar_permutacoes(int n, int k, int *seq, int *usado, int indice) {
    // Se a permutação está completa, imprime seq e retorna
    if (indice == k) {
        for (int j = 0; j < k; j++) {
            printf("%d ", seq[j]);
        }
        printf("\n");
        return;
    }

    // Esse loop tenta incluir cada número v, de 1 até n, na posição indice de seq
    for (int v = 1; v <= n; v++) {
        // Se o número v não foi usado
        if (!usado[v]) {
            // Coloca o número v em seq[indice]
            seq[indice] = v;
            // Marca o numero v como usado
            usado[v] = 1;
            // Chama recursivamente a função
            gerar_permutacoes(n, k, seq, usado, indice + 1);
            // Desfaz a marcação (backtracking)
            usado[v] = 0;
        }
    }
}

int main() {
    int n, k;
    printf("Digite o valor de n (quantidade de números): ");
    scanf("%d", &n);
    printf("Digite o valor de k (comprimento da permutação): ");
    scanf("%d", &k);

    if (k > n || n <= 0 || k <= 0) {
        printf("Valores inválidos! Certifique-se de que 0 < k <= n.\n");
        return 1;
    }

    // Declaração dos vetores
    int seq[k];
    int usado[n + 1];
    // Inicializando o vetor usado
    for (int i = 0; i <= n; i++) {
        usado[i] = 0;
    }

    printf("Gerando permutações de %d números com comprimento %d:\n", n, k);
    gerar_permutacoes(n, k, seq, usado, 0);

    return 0;
}
