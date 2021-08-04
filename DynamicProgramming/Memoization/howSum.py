"""
HOW SUM PROBLEM
Return an array containing numbers that when added sum up to the target sum
    howSum(7, [2, 3, 4]) => [3,4]
    howSum(8, [2, 3, 7]) => [2, 3, 3]

"""

"""
#BRUTE FORCE

def howSum(target, nums):
    if target == 0: return []
    if target < 0: return None
    for n in nums:
        rem = target - n
        remRes = howSum(rem, nums)
        if remRes != None:
            return [*remRes, n]
    return None
"""

#MEMOIZING SOLUTION
def howSum(target, nums, memo={}):
    if target in memo: return memo[target]
    if target == 0: return []
    if target < 0: return None
    for n in nums:
        rem = target - n
        remRes = howSum(rem, nums, memo)
        if remRes != None:
            memo[target] = [*remRes, n]
            return memo[target]
    memo[target] = None
    return None
"""
print(howSum(5, [2, 3, 1, 5]))
print(howSum(7, [2, 3]))
print(howSum(7, [5, 3, 4, 7]))
print(howSum(7, [2, 4]))
print(howSum(8, [2, 3, 5]))
print(howSum(300, [7, 14]))
print(howSum(20, [7, 7]))
"""
