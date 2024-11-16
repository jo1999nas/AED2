#include <stdio.h>

// Função recursiva para gerar todas as combinações
void gerar_combinacoes(int n, int m, int *sequencia, int posicao) {
    // Caso base: se a sequência está completa
    if (posicao == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", sequencia[i]);
        }
        printf("\n");
        return;
    }

    // Tentar todas as possibilidades para a posição atual
    // i começa em 1 porque o dado não tem uma face 0
    for (int i = 1; i <= m; i++) {
        sequencia[posicao] = i; // Escolhe uma face
        gerar_combinacoes(n, m, sequencia, posicao + 1); // Próxima posição
    }
}

int main() {
    int n, m;

    // Leitura dos dados
    printf("Digite a quantidade de dados (N): ");
    scanf("%d", &n);

    printf("Digite o número de faces de cada dado (M): ");
    scanf("%d", &m);

    // Vetor para armazenar a sequência atual
    int sequencia[n];

    printf("\nTodas as possíveis sequências:\n");
    gerar_combinacoes(n, m, sequencia, 0);

    return 0;
}
