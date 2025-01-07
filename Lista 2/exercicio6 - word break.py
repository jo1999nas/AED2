def word_break(s, wordDict):
    word_set = set(wordDict)    # Cria um set para armazenar as palavras
    memo = {}                   # Cria um dicionario para memoizar as operações
    
    def can_break(start):
        if start == len(s):     # Se chegarmos ao final da string, retorna True
            return True
        
        if start in memo:       # Se aquele valor de start já foi calculado, busca em memo
            return memo[start]
        
        # Testa para as diferentes substrings, de start até um end que cresce de 1 a 9
        # end não pode ser 0. Em python para representar a string usando [start:end]
        # o start será zero e o end será 1 excluido. ou seja de 0 a 1 só pega a letra em 0
        # pelo mesmo motivo o range vai até len(s) + 1. Numa string de 7 letras len(s) = 8
        # O range precisa ir até 9 para cobrir todos os valores possíveis
        for end in range(start + 1, len(s) + 1):
            substring = s[start:end]
            # Verifica se a string está em wordset e se é possível quebrar a parte restante
            if substring in word_set and can_break(end):
                memo[start] = True  # Se for, marca True em memo e retorna
                return True
        # Caso seja percorrida toda a string sem conseguir quebrar, marca e retorna False
        memo[start] = False
        return False
    
    # Por fim chama can_break do início da string
    return can_break(0)

s1 = "applepenapple"
wordDict1 = ["apple", "pen"]
print(word_break(s1, wordDict1))  # Saída: True

s2 = "catsandog"
wordDict2 = ["cats", "dog", "sand", "and", "cat"]
print(word_break(s2, wordDict2))  # Saída: False
