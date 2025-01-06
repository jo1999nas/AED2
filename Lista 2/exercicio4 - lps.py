def lps(s):
    # Calcula o tamanho da string
    tamanho = len(s)
    
    # Dicionário para armazenar os resultados de subproblemas
    memo = {}

    # Função recursiva que resolve o problema no intervalo [i, j]
    def solve(i, j):
        # Caso base 1: intervalo inválido
        if i > j:
            return 0
        
        # Caso base 2: intervalo com uma única letra (é um palíndromo de comprimento 1)
        if i == j:
            return 1
        
        # Caso já calculado, retornar o valor armazenado
        if (i, j) in memo:
            return memo[(i, j)]
        
        # Caso os caracteres nas extremidades sejam iguais
        if s[i] == s[j]:
            # O comprimento aumenta em 2, mais o resultado do intervalo interno [i+1, j-1]
            memo[(i, j)] = 2 + solve(i + 1, j - 1)
        else:
            # Caso os caracteres não sejam iguais,
            # o resultado é o máximo entre os intervalos [i+1, j] e [i, j-1]
            memo[(i, j)] = max(solve(i + 1, j), solve(i, j - 1))
        
        # Retorna o resultado armazenado no memo
        return memo[(i, j)]
    
    # Chama a função recursiva para o intervalo completo da string [0, tamanho - 1]
    return solve(0, tamanho - 1)

# Exemplo de uso
s = "bbabcbcab"
# O comprimento da subsequência palindrômica mais longa será calculado
print("O comprimento da subsequência palindrômica mais longa é:", lps(s))
