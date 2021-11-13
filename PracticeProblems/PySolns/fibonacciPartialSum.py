"""
PROBLEM STATEMENT
Given two non-negative integers m and n, m <= n
Find last digit of sum Fm + Fm+1 + ... Fn

Sample
3 7 --> 1
F3 + F4 + F5 + F6 + F7 = 2 + 3 + 5 + 8 + 13 = 31 = 1
"""
def fib(n):
    nums = [0, 1]
    if(n == 0):
        return 0
    if(n == 1):
        return 1
    for i in range(2, n+1):
        nums.append(nums[i-1] + nums[i-2])
    return nums[n]

def PartialSum(n, m):
    sumTotal = 0
    for i in range(n, m+1):
        sumTotal += fib(i)
    return sumTotal % 10

if __name__ == "__main__":
    n, m = map(int, input().split())
    print(PartialSum(n, m))
