def edit_distance_rec(str1, str2):
    n, m = len(str1), len(str2)
    def solve(i, j):
        if i == 0: return j
        if j == 0: return i
        if str1[i - 1] == str2[j - 1]:
            return solve(i - 1, j - 1)
        else:
            insert = solve(i, j - 1)
            remove = solve(i - 1, j)
            replace = solve(i - 1, j - 1)
        return 1 + min(insert, remove, replace)
    return solve(n, m)
    
a = "horse"
b = "ros"
result = edit_distance_rec(a, b)
print(f"Distância de edição entre '{a}' e '{b}' é: {result}")
