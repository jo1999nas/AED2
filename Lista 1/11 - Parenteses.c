#include <stdio.h>
#include <stdlib.h>

int fatorial(int n){
    if(n == 0)
        return 1;
    return n*fatorial(n - 1);
}

int catalan(int n){
    int binomial = fatorial(2*n)/(fatorial(n)*fatorial(n));
    return binomial/(n + 1);
}

int main(){
    int n;
    printf("Insira um numero: ");
    scanf("%d", &n);
    printf("O numero de parênteses bem-formados com %d parênteses é %d\n", n, catalan(n));
    return 0;
}
