def lcs(p, q, n, m):
    if n == 0 or m == 0:
        resultado = 0
    elif p[n-1] == q[m-1]:
        resultado = 1 + lcs(p, q, n - 1, m - 1)
    else:
        temp1 = lcs(p, q, n - 1, m)
        temp2 = lcs(p, q, n, m - 1)
        resultado = max(temp1, temp2)
    return resultado
