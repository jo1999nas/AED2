def edit_distance_dp(str1, str2):
    n, m = len(str1), len(str2)
    memo = [[-1] * (m + 1) for _ in range(n + 1)]
    def solve(i, j):
        if i == 0: 
            return j 
        if j == 0: 
            return i 
        if memo[i][j] != -1:
            return memo[i][j]
        if str1[i - 1] == str2[j - 1]:
            memo[i][j] = solve(i - 1, j - 1)
        else:
            insert = solve(i, j - 1)
            remove = solve(i - 1, j) 
            replace = solve(i - 1, j - 1)
            memo[i][j] = 1 + min(insert, remove, replace)
        return memo[i][j]
    return solve(n, m)

a = "horse"
b = "ros"
result = edit_distance_dp(a, b)
print(f"Distância de edição entre '{a}' e '{b}' é: {result}")
