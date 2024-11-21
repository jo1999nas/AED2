#include <stdio.h>
#include <limits.h>


int forcaBruta(int *vetor, int tamanho){
    int i, j, k, soma;
    int maiorSoma = vetor[0];
    for(i = 0; i < tamanho; i++){
        for(j = i; j < tamanho; j++){
            soma = 0;
            for(k = i; k < j; k++){
                soma += vetor[k];
            }
            if(soma >= maiorSoma){
                maiorSoma = soma;
            }
        }
    }
    return maiorSoma;
}

int maximaSomaCruzada(int *vetor, int inicio, int meio, int fim){
    int somaMaximaEsquerda = -99999;                // Iniciamos a soma esquerda atual com um valor suficientemente pequeno
    int somaAcumulada = 0;                          // A soma acumulada guarda o valor de todos os elementos somados até o momento
    for(int i = meio; i >= inicio; i--){            // Devemos sair do meio em direção ao inicio do vetor
        somaAcumulada += vetor[i];                  // O valor em vetor[i] é adicionado a soma acumulada
        if(somaAcumulada > somaMaximaEsquerda){     // Se a soma acumulada é maior que a soma máxima
            somaMaximaEsquerda = somaAcumulada;     // Atualiza a soma máxima
        }
    }
    // Fazemos o mesmo processo, agora do meio para o final do vetor
    int somaMaximaDireita = -99999;
    somaAcumulada = 0;
    for(int i = meio + 1; i <= fim; i++){
        somaAcumulada += vetor[i];
        if(somaAcumulada > somaMaximaDireita){
            somaMaximaDireita = somaAcumulada;
        }
    }
    return somaMaximaEsquerda + somaMaximaDireita;  // No final retornamos as somas dos dois lados somadas
}

int maximoSubvetorDC(int *vetor, int inicio, int fim){
    // Caso base: O subvetor tem apenas um elemento
    if(inicio == fim){
        return vetor[inicio];
    }
    // Calcula o meio do vetor
    int meio = (inicio + fim)/2;
    
    // Calcula recursivamente as somas da esquerda e da direita
    int somaEsquerda = maximoSubvetorDC(vetor, inicio, meio);
    int somaDireita = maximoSubvetorDC(vetor, meio + 1, fim);
    
    // Calcula a soma cruzada
    int somaCruzada = maximaSomaCruzada(vetor, inicio, meio, fim);
    // Tendo os três valores, retornamos o maior dentre eles
    if(somaEsquerda >= somaDireita && somaEsquerda >= somaCruzada){
        return somaEsquerda;
    }
    else if(somaDireita >= somaEsquerda && somaDireita >= somaCruzada){
        return somaDireita;
    }
    else
        return somaCruzada;
}

int main() {
    // Definição do vetor
    int vetor[] = {-3, 2, 1, -4, 5, 2, -1, 3, -1};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    // Chama a função e imprime o resultado
    //int somaMaxima = forcaBruta(vetor, tamanho);
    int somaMaxima =  maximoSubvetorDC(vetor, 0, tamanho - 1);
    printf("A soma máxima do subvetor contíguo é: %d\n", somaMaxima);

    return 0;
}
