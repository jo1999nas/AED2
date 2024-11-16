#include <stdio.h>
#include <stdlib.h>

#define N 8

void constroiTabuleiro(int tabuleiro[N][N], int tamanho){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            tabuleiro[i][j] = 0;
        }
    }
}

void imprimeTabuleiro(int tabuleiro[N][N], int tamanho){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função que verifica se é seguro colocar a torre numa posição
// Dada uma posição, ela verifica se há alguma torre em todas as linhas acima na coluna específicada
int ehSeguro(int tabuleiro[N][N], int linha, int coluna){
    for(int i = 0; i < linha; i++){     // Verifica todas a coluna em todas as linhas acima
        if(tabuleiro[i][coluna] == 1)
            return 0;   // Já existe uma torre na coluna
    }
    return 1;   // Não há nenhuma torre, pode colocar
}

// Função de backtracking para colocar as torres
int colocarTorres(int tabuleiro[N][N], int linha) {
    // Se chegou na última linha todas as torres foram colocadas
    if (linha == N) {
        return 1;
    }

    // Verifica cada coluna de uma mesma linha
    for (int coluna = 0; coluna < N; coluna++) {
        // Se é seguro colocar a torre
        if (ehSeguro(tabuleiro, linha, coluna)) {
            tabuleiro[linha][coluna] = 1; // Coloca a torre

            // Tenta colocar a próxima torre recursivamente
            if (colocarTorres(tabuleiro, linha + 1)) {
                return 1; // Se a próxima linha foi preenchida, retorne sucesso
            }

            tabuleiro[linha][coluna] = 0; // Remove a torre (backtrack)
        }
    }
    return 0; // Não foi possível colocar todas as torres
}

int main()
{
    int tab[N][N];
    constroiTabuleiro(tab, N);
    colocarTorres(tab, 0);
    imprimeTabuleiro(tab, N);
    return 0;
}
