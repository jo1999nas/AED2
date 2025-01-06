nums = [10, 9, 2, 5, 3, 7, 101, 18]

def lis(nums):
    memo = [1] * len(nums)
    for i in range(len(nums) - 1, -1, -1):
        for j in range(i + 1, len(nums)):
            if nums[i] < nums[j]:
                memo[i] = max(memo[i], 1 + memo[j])
    return max(memo)

lis = lis(nums)

print(f"O comprimento da maior sequencia crescente é {lis}")
