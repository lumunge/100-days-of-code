"""
Given an integer n, find last digit of sum f1 + f2 + ... + fn

sample: 3 -> 4
    f0 + f1 + f2 + f3 + f4 = 0 + 1 + 1 + 2 = 4
"""

def fib(n):
    nums = [0, 1]
    if(n == 0):
        return 0
    if(n == 1):
        return 1
    for i in range(2, n+1):
        nums.append(nums[i-1] + nums[i-2])
    
    return sum(nums) % 10

if __name__ == '__main__':
    n = int(input())
    print(fib(n))



