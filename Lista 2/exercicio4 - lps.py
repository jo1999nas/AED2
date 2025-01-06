def lps(s, i, j):
    memo = {}

    if i > j:
        return 0
    if i == j:
        return 1
    if (i, j) in memo:
        return memo[(i, j)]
            
    if s[i] == s[j]:
        memo[(i, j)] = 2 + lps(s, i + 1, j - 1)
    else:
        memo[(i, j)] = max(lps(s, i + 1, j), lps(s, i, j - 1))
    return memo[(i, j)]

s = "bbabcbcab"
print("O comprimento da LPS é:", lps(s, 0, len(s)-1))
