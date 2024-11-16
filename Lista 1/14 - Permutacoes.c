#include <stdio.h>

void gerar_permutacoes(int n, int k, int *seq, int *usado, int i) {
    if (i == k) {
        for (int j = 0; j < k; j++) {
            printf("%d ", seq[j]);
        }
        printf("\n");
        return;
    }

    for (int v = 1; v <= n; v++) {
        if (!usado[v]) {
            seq[i] = v;
            usado[v] = 1;
            gerar_permutacoes(n, k, seq, usado, i + 1);
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
