def mochila_PD(item, capacidade):
	if memo[item][capacidade] != -1:			# Se já foi calculado, retorna imediatamente
		return memo[item][capacidade]
	if item == 0 or capacidade == 0:
		resultado = 0
	elif peso[item] > capacidade:
		resultado = mochila_PD(item - 1, capacidade)
	else:
		nao_coloca = mochila_PD(item - 1, capacidade)
		coloca = valor[item] + mochila_PD(item - 1, capacidade - peso[item])
		resultado = max(nao_coloca, coloca)
		memo[item][capacidade] = resultado								# Salva o resultado obtido em memo
	return resultado

peso = [0, 2, 3, 4, 5]
valor = [0, 3, 4, 5, 6]
capacidade = 5
n = len(peso) - 1
memo = [[-1 for _ in range(capacidade + 1)] for _ in range(n + 1)]

resultado = mochila_PD(n, capacidade)
print(f"Programação Dinâmica: O valor máximo que pode ser carregado é {resultado}")
