def mochila(item, capacidade):
	if item == 0 or capacidade == 0:
		resultado = 0
	elif peso[item] > capacidade:
		resultado = mochila(item - 1, capacidade)
		
	else:
		nao_coloca = mochila(item - 1, capacidade)
		coloca = valor[item] + mochila(item - 1, capacidade - peso[item])
		resultado = max(nao_coloca, coloca)
	return resultado

peso = [0, 2, 3, 4, 5]
valor = [0, 3, 4, 5, 6]
capacidade = 5
n = len(peso) - 1

resultado = mochila(n, capacidade)
print(f"O valor máximo que pode ser carregado é {resultado}")
